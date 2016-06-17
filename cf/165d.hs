{-# LANGUAGE BangPatterns, MagicHash #-}

import Control.Applicative

import Control.Monad
import Control.Monad.ST
import Debug.Trace
import Data.Array
import Data.Array.ST
import Data.Bits
import qualified Data.ByteString.Char8 as B
import Data.Graph
import Data.List
import Data.Maybe
import Data.Tree
import Data.Tuple
import GHC.Prim
import GHC.Types

type Fenwick s = STUArray s Int Int
fenwick l = newArray (0, l-1) 0 :: ST s (Fenwick s)

update f i d = do
	l <- snd <$> getBounds f
	let next (I# i) = I# (i `orI#` (i +# 1#))
	-- let is = takeWhile (<= l) $ iterate (\i -> i .|. (i + 1)) i
	let is = takeWhile (<= l) $ iterate next i
	forM_ is $ \i -> do
		v <- readArray f i
		writeArray f i (v + d)
	return f

foldM' :: (Monad m) => (a -> b -> m a) -> a -> [b] -> m a
foldM' _ z [] = return z
foldM' f z (x:xs) = do
  z' <- f z x
  z' `seq` foldM' f z' xs

-- a `andI#` b = word2Int# (int2Word# a `and#` int2Word# b)
-- a `orI#` b = word2Int# (int2Word# a `or#` int2Word# b)

query f (-1) = return 0
query f i = do
	-- let next i = (i .&. (i+1)) - 1
	let next (I# i) = I# ((i `andI#` (i +# 1#)) -# 1#)
	-- let next (I# i) = I# $ word2Int# $ (int2Word# i) or# (int2Word# i)
	-- sum <$> (mapM (readArray f) $ takeWhile (>= 0) $ iterate next i)
	foldM' (\s i -> (s+) <$> (readArray f i)) 0 $ takeWhile (>= 0) $ iterate next i
{-query f i = query1 f i 0

query1 f i r
	| i < 0 = return r
	| otherwise = do
		v <- readArray f i 
		query1 f i' (r + v)
	where
		i' = i .&. (i + 1) - 1

query'' f !i
	| i < 0 = return 0
	| otherwise = do
		v <- readArray f i
		r <- query f i'
		return $ v + r
	where
		i' = i .&. (i + 1) - 1 -}



unordered edges = edges ++ map swap edges

solve n edges queries = runST $ do
		fenwicksList <- mapM (fenwick . length) paths

		let
			fenwicks = listArray (1, length paths) fenwicksList

		reverse <$> foldM (\rs q -> case q of
			[t, edgeIndex] -> do
				let
					(fenwicksIndex, index) = edgesPlaces edgeIndex
					fenwick = fenwicks ! fenwicksIndex
				update fenwick index (if t == 1 then -1 else 1)
				return rs
			[3, i, j] -> do
				let (i1, j1) = places ! i
				let (i2, j2) = places ! j
				s1 <- query (fenwicks ! i1) j1
				s2 <- query (fenwicks ! i2) j2

				let !d = if i1 == i2
                                        then if s1 == s2 then abs (j1 - j2) else -1
					else if s1 + s2 == 0 then j1 + j2 + 2 else -1
				return $ d : rs) [] queries

	where
		g = buildG (1, n) (unordered edges)
		root = fromMaybe 1 $ find (\i -> indegree g ! i > 2) [1..n]
		paths = map flatten $ subForest $ head $ dfs g [root]

		parents = accumArray (flip const) 0 (1, n) $ concat [path `zip` (root:path) | path <- paths] 

		places = accumArray (flip const) (1, -1) (1, n) $
			[(vertex, (pathIndex, index)) | (path, pathIndex) <- paths `zip` [1..],
				(vertex, index) <- path `zip` [0..]]

		edges' = listArray (1, length edges) edges
		edgesPlaces edgeIndex = places ! k
			where
				(i, j) = edges' ! edgeIndex
				k = if parents ! i == j then i else j

readInts = map (fst . fromJust . B.readInt) . B.words <$> B.getLine

main = do
	[n] <- readInts
	edges <- map (\[a, b] -> (a, b)) <$> replicateM (n - 1) readInts
	[m] <- readInts
	queries <- replicateM m readInts
	putStrLn $ unlines $ map show $ solve n edges queries
