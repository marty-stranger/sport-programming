{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}

import Control.Applicative ((<$>))
import Control.Monad (replicateM)
import Data.ByteString.Char8 (readInt, words, getLine)
import Data.List (sort, splitAt, unfoldr)
import Data.Maybe (fromJust)
import Prelude hiding (getLine, words)

data Point = Point !Int !Int deriving (Eq, Ord)
data Vector = Vector !Int !Int deriving (Eq)

(Point x2 y2) -. (Point x1 y1) = Vector (x2 - x1) (y2 - y1)
(Vector x y) *. f = Vector (x * f) (y * f)

readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

splitEvery n = unfoldr $ \xs -> if null xs then Nothing else Just $ splitAt n xs
readPoints = map (\[a, b] -> Point a b) . splitEvery 2 <$> readInts

solve pattern canditate =
    and $ map (\(v1, v2) -> v1 *. s2 == v2 *. s1) (zip vs1 vs2)
  where
    (s1, vs1) = scaleAndVectors pattern
    (s2, vs2) = scaleAndVectors canditate

    scaleAndVectors ps = (s, vs)
      where
        ps' = sort ps
        s = max (abs x) (abs y) where (Vector x y) = (ps' !! 1) -. (ps' !! 0)
        vs = map (-. head ps') (tail ps')

main = do
  [n, m] <- readInts

  pattern <- readPoints
  canditates <- replicateM n readPoints

  let rs = if m == 1
      then replicate n True
      else map (solve pattern) canditates

  putStr $ unlines $ map (\v -> if v then "YES" else "NO") rs
