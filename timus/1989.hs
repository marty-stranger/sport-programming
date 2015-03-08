{-# LANGUAGE NPlusKPatterns, BangPatterns, MagicHash #-}

import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.Array.ST
import Data.Array.Unboxed (UArray, (!), listArray)
import Data.Bits
import Data.ByteString.Char8 (readInt, words, getContents, lines)
import qualified Data.ByteString.Char8 as BS
import Data.Char
import Data.Int
import Data.Maybe
import Debug.Trace
import GHC.Prim
import GHC.Types
import Prelude hiding (words, lines, getContents)

type Fenwick s = STUArray s Int Int64

makeFenwick n = newArray (0, n-1) 0 :: ST s (Fenwick s)

a `andI#` b = word2Int# (int2Word# a `and#` int2Word# b)
a `orI#` b = word2Int# (int2Word# a `or#` int2Word# b)

update f (i + 1) d = do
	n <- snd <$> getBounds f
	let next (I# i) = I# (i `orI#` (i +# 1#))
	let is = takeWhile (<= n) $ iterate next i
	-- let is = takeWhile (<= n) $ iterate (\i -> i .|. (i + 1)) i
	forM_ is $ \i -> do
		v <- readArray f i
		writeArray f i (v + d)

foldM' :: (Monad m) => (a -> b -> m a) -> a -> [b] -> m a
foldM' _ z [] = return z
foldM' f z (x:xs) = do
  z' <- f z x
  z' `seq` foldM' f z' xs

query f 0 = return 0
query f (i + 1) = do
	-- let is = takeWhile (>= 0) $ iterate (\i -> (i .&. (i+1)) - 1) i
	-- sum <$> mapM (readArray f) is
	let next (I# i) = I# ((i `andI#` (i +# 1#)) -# 1#)
	foldM' (\s i -> (s+) <$> (readArray f i)) 0 $ takeWhile (>= 0) $ iterate next i

data Hashs s = Hashs Int (Fenwick s) (UArray Int Int64) Bool

base :: Int64
base = 13

modulo :: Int64
modulo = 10^9 + 7

a +. b = (a + b) `rem` modulo
a *. b = (a * b) `rem` modulo
a -. b = (a - b + modulo) `rem` modulo

makeHashs s rev = do
		fenwick <- makeFenwick n
		forM_ (zip (BS.unpack s') [1..]) $ \(c, i) -> do
			let d = (fromIntegral (ord c - ord 'a')) *. (coefs ! (i - 1))
			update fenwick i d
		return $ Hashs n fenwick coefs rev	
	where
		n = BS.length s
		coefs = listArray (0, n-1) $ iterate (*. base) 1
		s' = if rev then BS.reverse s else s
		
hashsQuery :: Hashs s -> Int -> Int -> ST s Int64
hashsQuery (Hashs n fenwick coefs rev) l r = do
		v1 <- query fenwick r'
		v2 <- query fenwick (l' - 1)
		let v = v1 -. v2

		return $ if l'+r' <= n+1 then v *. (coefs ! (n+1-r'-l')) else v
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
		vv = (fromIntegral (ord c - ord 'a')) *. (coefs ! (i' - 1))

readInt' = fst . fromJust . readInt

solve :: BS.ByteString -> [Op] -> [Bool]
solve s ops = runST $ do
	lr <- makeHashs s False
	rl <- makeHashs s True

{-
	vs <- forM ops $ \op -> case op of
		(OpChange i c) -> do
			hashsUpdate lr i c
			hashsUpdate rl i c
			return ""
		(OpQuery i j) -> do
			v1 <- hashsQuery lr i j
			v2 <- hashsQuery rl i j
			return $ if v1 == v2 then "Yes" else "No"
-}

	reverse <$> foldM (\rs op -> case op of
		(OpChange i c) -> do
			hashsUpdate lr i c
			hashsUpdate rl i c
			return rs
		(OpQuery i j) -> do
			v1 <- hashsQuery lr i j
			v2 <- hashsQuery rl i j
			let !r = v1 == v2
			return $ r : rs
		) [] ops

data Op = OpChange !Int !Char | OpQuery !Int !Int deriving (Show)

readOp s =
		if (BS.head a) == 'c'
			then OpChange (readInt' b) (BS.head c)
			else OpQuery (readInt' b) (readInt' c)
	where
		[a, b, c] = words s

main = do
	s <- BS.getLine
	m <- readInt' <$> BS.getLine
	ops <- map readOp <$> replicateM m BS.getLine

	putStrLn . unlines . (map (\v -> if v then "Yes" else "No")) $ solve s ops


