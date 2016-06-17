{-# OPTIONS_GHC -O2 -XUnsafe #-}

import Control.Applicative ((<$>))
import Control.Monad (forM, forM_, replicateM)
import Control.Monad.ST (ST, runST)
import qualified Data.Tree as Tree
import qualified Data.Graph as Graph
import Data.Array (listArray, accumArray, (!))
import Data.Array.ST (STUArray, newArray, getBounds, readArray, writeArray)
import Data.Bits ((.|.), (.&.))
import Data.ByteString (getLine, getContents)
import Data.ByteString.Char8 (readInt, words, lines)
import Data.List (find)
import Data.Maybe (fromMaybe, fromJust, isJust)
import Data.Tuple (swap)
import Prelude hiding (getLine, words, lines)

type Fenwick s = STUArray s Int Int

fenwick l = newArray (0, l-1) 0 :: ST s (Fenwick s)

update f i d = do
		l <- snd <$> getBounds f
		forM_ (takeWhile (<= l) $ iterate next i) $ \i -> do
			v <- readArray f i
			writeArray f i $ v + d
  	where
	   	next i = i .|. (i + 1)

query f (-1) = return 0
query f i = do
		sum <$> mapM (readArray f) . takeWhile (>= 0) $ iterate next i
	where
	 	next i = (i .&. (i+1)) - 1

readInts = map (fst . fromJust . readInt) . words <$> getLine

main = do
	[n] <- readInts
	edges <- map (\[a, b] -> (a, b)) <$> replicateM (n - 1) readInts
	[m] <- readInts
	queries <- replicateM m readInts
 	
	let

		answers = map fromJust . filter isJust $ runST $ do
				fenwicks <- listArray (1, length lines) <$> mapM (fenwick . length) lines

				forM queries $ \q -> case q of
			  		[t, edgeIx] -> do
						let (i, j) = byEdge ! edgeIx
	  					update (fenwicks ! i) j $ if t == 1 then -1 else 1
						return Nothing
	     				[3, u, v] -> do
						let (i1, j1) = byVertex ! u
						let (i2, j2) = byVertex ! v
	  					s1 <- query (fenwicks ! i1) j1
	  					s2 <- query (fenwicks ! i2) j2
						return . Just $ if i1 == i2
							then if s1 == s2 then abs (j1 - j2) else -1
							else if s1 + s2 == 0 then j1 + j2 + 2 else -1

	  		where
	     			g = Graph.buildG (1, n) $ edges ++ map swap edges

				root = fromMaybe 1 $ find (\i -> Graph.indegree g ! i > 2) [1..n]
	     			lines = map Tree.flatten $ Tree.subForest $ head $ Graph.dfs g [root]

				byVertex = accumArray (flip const) (1, -1) (1, n) $
					[(u, (i, j)) | (line, i) <- lines `zip` [1..], (u, j) <- line `zip` [0..]]

				byEdge = listArray (1, length edges) $ map f edges
    					where
		 				f (u, v) = byVertex ! (if parents ! u == v then u else v)
						parents = accumArray (flip const) 0 (1, n) $ concat [line `zip` (root:line) | line <- lines] 

	putStrLn . unlines $ map show answers
