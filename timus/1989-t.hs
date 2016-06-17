{- tle 14 -}
{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}
{-# LANGUAGE NPlusKPatterns, BangPatterns, MagicHash #-}

import Control.Applicative ((<$>))
import Control.Monad (forM, forM_, replicateM)
import Control.Monad.ST (runST, ST)

import Data.Bits ((.&.), (.|.))
import Data.ByteString.Char8 (readInt, words, getContents, lines)
import qualified Data.ByteString.Char8 as BS
import Data.Char (ord)
import Data.Int (Int)
import Data.Maybe (fromJust)

import qualified Data.Vector.Unboxed as UVector
import qualified Data.Vector.Unboxed.Mutable as MVector

import GHC.Prim
import GHC.Types

import Prelude hiding (words, lines, getContents)

type Fenwick s = MVector.STVector s Int

a `andI#` b = word2Int# (int2Word# a `and#` int2Word# b)
a `orI#` b = word2Int# (int2Word# a `or#` int2Word# b)

foldM' :: (Monad m) => (a -> b -> m a) -> a -> [b] -> m a
foldM' _ z [] = return z
foldM' f z (x:xs) = do
  z' <- f z x
  z' `seq` foldM' f z' xs

makeFenwick n = MVector.new n

update f (i + 1) d = do
		let next (I# i) = I# (i `orI#` (i +# 1#))
		let !is = takeWhile (<= n) $ iterate next i
		-- let is = takeWhile (<= n) $ iterate (\i -> i .|. (i + 1)) i
		forM_ is $ \i -> do
			v <- MVector.unsafeRead f i
			MVector.unsafeWrite f i (v + d)
	where
		n = MVector.length f

query f 0 = return 0
query f (i + 1) = do
	-- let is = takeWhile (>= 0) $ iterate (\i -> (i .&. (i+1)) - 1) i
	-- sum <$> mapM (readArray f) is
	let next (I# i) = I# ((i `andI#` (i +# 1#)) -# 1#)
	foldM' (\s i -> (s+) <$> (MVector.read f i)) 0 $ takeWhile (>= 0) $ iterate next i

data Hashs s = Hashs Int (Fenwick s) (UVector.Vector Int) Bool

base = 13 :: Int
modulo = 10^9 + 7 :: Int

a +. b = (a + b) `rem` modulo
a *. b = (a * b) `rem` modulo
a -. b = (a - b + modulo) `rem` modulo

makeHashs s rev = do
		fenwick <- makeFenwick n
		forM_ (zip (BS.unpack s') [1..]) $ \(c, i) -> do
			let d = (fromIntegral (ord c - ord 'a')) *. (coefs UVector.! (i - 1))
			update fenwick i d
		return $ Hashs n fenwick coefs rev	
	where
		n = BS.length s
		coefs = UVector.fromList $ take n $ iterate (*. base) 1
		s' = if rev then BS.reverse s else s
		
hashsQuery :: Hashs s -> Int -> Int -> ST s Int
hashsQuery (Hashs n fenwick coefs rev) l r = do
		v1 <- query fenwick r'
		v2 <- query fenwick (l' - 1)
		let v = v1 -. v2

		return $ if l'+r' <= n+1 then v *. (coefs UVector.! (n+1-r'-l')) else v
	where
		(l', r') = if rev then (n+1-r, n+1-l) else (l, r)

hashsUpdate :: Hashs s -> Int -> Char -> ST s ()
hashsUpdate (Hashs n fenwick coefs rev) i c = do
		v1 <- query fenwick i'
		v2 <- query fenwick (i' - 1)
		let p = v1 -. v2
		update fenwick i' (vv - p)
	where
		i' = if rev then n+1-i else i
		vv = (fromIntegral (ord c - ord 'a')) *. (coefs UVector.! (i' - 1))

data Op = OpChange !Int !Char | OpQuery !Int !Int deriving (Show)

main = do
		s <- BS.getLine
		m <- readInt' <$> BS.getLine
		ops <- map readOp <$> replicateM m BS.getLine

		let answers = runST $ do
			lr <- makeHashs s False
			rl <- makeHashs s True

			vs <- forM ops $ \op -> case op of
				(OpChange i c) -> do
					hashsUpdate lr i c
					hashsUpdate rl i c
					return ""
				(OpQuery i j) -> do
					v1 <- hashsQuery lr i j
					v2 <- hashsQuery rl i j
					return $ if v1 == v2 then "Yes" else "No"

			return $ filter (not . null) vs

		putStrLn . unlines $ answers

	where
		readInt' = fst . fromJust . readInt

		readOp s =
				if (BS.head a) == 'c'
					then OpChange (readInt' b) (BS.head c)
					else OpQuery (readInt' b) (readInt' c)
			where
				[a, b, c] = words s
