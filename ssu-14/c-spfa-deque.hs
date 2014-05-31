{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}

import Control.Applicative ((<$>))
import Control.Monad (foldM, replicateM)
import Control.Monad.ST (runST, ST)
import Data.ByteString.Char8 (readInt, words, getLine)
import Data.List (sort)
import Data.Maybe (fromJust)

import qualified Data.Dequeue as DQ

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


spfa graph = runST $ do
    distances <- MVector.replicate n (10^9 :: Int)
    MVector.write distances source 0
    bs <- MVector.replicate n False

    let spfa' q
          | DQ.null q = return ()
          | otherwise = do
            b <- MVector.write bs v True
            q'' <- foldM relax q' es
            spfa' q''
            return ()
          where
            (Just !v, q') = DQ.popFront q
            es = graph Vector.! v
            relax !q (EdgeTo u w) = do
              b <- MVector.read bs u
              if b then
                return q
              else do
                du <- MVector.read distances u
                dv <- MVector.read distances v
                if dv + w < du
                then do
                  MVector.write distances u (dv + w)
                  if w == 1
                  then
                    return $ DQ.pushBack q u
                  else
                    return $ DQ.pushFront q u
                else do
                  return q

    spfa' queue
    distances' <- Vector.freeze distances
    return $ Vector.toList distances'
  where
    n = Vector.length graph
    source = 0
    queue = DQ.fromList [source] :: DQ.BankersDequeue Int

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
        d = last $ spfa g

main = do
  [n, m] <- readInts
  edges <- replicateM m readInts

  if m == 0 then
    print $ -1
  else
    print $ solve n $ map (\[u, v, w] -> Edge (u-1) (v-1) w) edges
