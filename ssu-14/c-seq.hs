{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}

import Control.Applicative ((<$>))
import Control.Monad (replicateM)
import qualified Data.Foldable as Foldable
import Data.ByteString.Char8 (readInt, words, getLine)
import Data.List (sort)
import Data.Maybe (fromJust)
import Data.Vector (Vector)
import qualified Data.Set as Set
import qualified Data.Sequence as Seq
import qualified Data.Vector as Vector
import Prelude hiding (getLine, readInt, words)

import Debug.Trace (trace)

-- readInts = map read . words <$> getLine
readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

type Vertex = Int
type Weight = (Int, Int)
data Edge = Edge !Vertex !Vertex Weight
data EdgeTo = EdgeTo !Vertex !Weight
type Graph = Vector [EdgeTo]

edgesTo g v = g Vector.! v
vertexCount g = Vector.length g

(a, b) +. (c, d) = (a + c, b + d)
(a, b) <. (c ,d) = a < c || a == c && b > d

dijkstra graph =
    dijkstra' browsed queue distances
  where
    n = vertexCount graph
    source = 0
    queue = Set.singleton (0, 0)
    browsed = Set.singleton 0
    distances = Seq.fromList [(if v == source then (0, 0) else (10^9, 0)) | v <- [0..n-1]]

    dijkstra' bs q ds
        | Set.null q = ds
        | otherwise = dijkstra' bs' q'' ds'
      where
        ((d, v), q') = Set.deleteFindMin q
        bs' = Set.insert v bs
        es = edgesTo graph v
        relax (q, ds) (EdgeTo u w) =
            if (Set.notMember u bs') && d' +. w <. ds `Seq.index` u
              then (q', ds')
              else (q, ds)
          where
             d' = ds `Seq.index` v +. w
             q' = Set.insert (d', u) q
             ds' = Seq.update u d' ds

        (q'', ds') = foldl relax (q', ds) es

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
        d = last $ Foldable.toList $ dijkstra g

main = do
  [n, m] <- readInts
  edges <- replicateM m readInts

  if m == 0 then
    print $ -1
  else
    print $ solve n $ map (\[u, v, w] -> Edge (u-1) (v-1) w) edges
