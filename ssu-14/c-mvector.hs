{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}

import Control.Applicative ((<$>))
import Control.Monad (foldM, replicateM)
import Control.Monad.ST (runST, ST)
import Data.ByteString.Char8 (readInt, words, getLine)
import Data.List (sort)
import Data.Maybe (fromJust)
import qualified Data.Set as Set
import qualified Data.Sequence as Seq

import Data.Vector (Vector)
import qualified Data.Vector as Vector
import qualified Data.Vector.Mutable as MVector

import Prelude hiding (getLine, readInt, words)

import Debug.Trace (trace)

-- readInts = map read . words <$> getLine
readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

type Vertex = Int
type Weight = Int
data Edge = Edge !Vertex !Vertex !Weight
data EdgeTo = EdgeTo !Vertex !Weight
type Graph = Vector [EdgeTo]

dijkstra graph = runST $ do
    distances <- MVector.replicate n (10^9 :: Int)
    MVector.write distances source 0

    let dijkstra' q
          | Set.null q = return ()
          | otherwise = do
            q'' <- foldM relax q' es
            dijkstra' q''
            return ()
          where
            ((d, v), q') = Set.deleteFindMin q
            es = graph Vector.! v
            relax q (EdgeTo u w) = do
                d <- MVector.read distances u

                if d' < d
                then do
                  MVector.write distances u d'
                  return $ Set.insert (d', u) q
                else
                  return q
              where
                d' = d + w

    dijkstra' queue
    distances' <- Vector.freeze distances
    return $ Vector.toList distances'
  where
    n = Vector.length graph
    source = 0
    queue = Set.singleton (0, source)

graph n edges = Vector.accum (flip (:)) empty edgesTo
  where
    empty = Vector.replicate n []
    edgesTo = map update $ edges ++ map reverse edges
      where
        update (Edge u v w) = (u, EdgeTo v w)
        reverse (Edge u v w) = Edge v u w

solve n edges =
    search 0 (length edges - 1)
  where
    weights = Vector.fromList $ sort $ map (\(Edge _ _ w) -> w) edges

    search l r
       | l >= r = if d > 10^9 then -1 else w
       | d > 1 = search (m + 1) r
       | otherwise = search l m
      where
        m = (l + r) `div` 2
        w = weights Vector.! m
        g = graph n $ map (\(Edge u v ew) -> Edge u v (if ew > w then 1 else 0)) edges
        d = last $ dijkstra g

main = do
  [n, m] <- readInts
  edges <- replicateM m readInts

  if m == 0 then
    print $ -1
  else
    print $ solve n $ map (\[u, v, w] -> Edge (u-1) (v-1) w) edges
