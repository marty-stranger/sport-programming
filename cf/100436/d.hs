{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}

import Control.Applicative ((<$>))
import Control.Monad (replicateM)
import qualified Data.Foldable as Foldable
import Data.ByteString.Char8 (readInt, words, getLine)
import Data.List (sort)
import Data.Maybe (fromJust)
import Data.Array (Array)
import qualified Data.Set as Set
import qualified Data.Sequence as Seq
import qualified Data.Array as Array
import Prelude hiding (getLine, readInt, words)

import Debug.Trace (trace)

readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

type Vertex = Int
type Weight = (Int, Int)
data Edge = Edge !Vertex !Vertex Weight
data EdgeTo = EdgeTo !Vertex Weight
type Graph = Array Vertex [EdgeTo]

edgesTo g v = g Array.! v
vertexCount g = snd $ Array.bounds g + 1

(a, b) +. (c, d) = (a + c, b + d)

dijkstra graph =
    dijkstra' browsed queue distances
  where
    n = vertexCount graph
    source = 0
    queue = Set.singleton ((0, 0), source)
    browsed = Set.singleton source
    distances = Seq.fromList [(if v == source then (0, 0) else (10^10, 0)) | v <- [0..n-1]]

    dijkstra' bs q ds
        | Set.null q = ds
        | otherwise = dijkstra' bs' q'' ds'
      where
        ((d, v), q') = Set.deleteFindMin q
        bs' = Set.insert v bs
        es = edgesTo graph v
        relax (q, ds) (EdgeTo u w) =
            if Set.notMember u bs' && d' < (ds `Seq.index` u)
              then (q', ds')
              else (q, ds)
          where
             d' = ds `Seq.index` v +. w
             q' = Set.insert (d', u) q
             ds' = Seq.update u d' ds

        (q'', ds') = foldl relax (q', ds) es

graph n edges = Array.accumArray (flip (:)) [] (0, n - 1) edgesTo
  where
    edgesTo = map update $ edges ++ map reverse edges
      where
        update (Edge u v w) = (u, EdgeTo v w)
        reverse (Edge u v w) = Edge v u w

solve n edges =
    last $ Foldable.toList $ dijkstra g
  where
    g = graph n edges

main = do
  [n, m] <- readInts
  edges <- replicateM m readInts

  let edges' = map (\[u, v, w] -> Edge (u - 1) (v - 1) (w, -1)) edges
  let r = solve n edges'

  putStrLn $ (show (fst r)) ++ " " ++ (show (- (snd r)))
