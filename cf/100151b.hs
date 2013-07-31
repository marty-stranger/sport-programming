{-# LANGUAGE UnicodeSyntax #-}

import Control.Applicative
import Control.Monad
import Data.List
import System.IO

data Segment = Segment { segmentX1 :: Int, segmentY1 :: Int, segmentX2 :: Int, segmentY2 :: Int }

makeSegment x1 y1 x2 y2 = Segment x1' y1' x2' y2'
    where
        [x1', x2'] = sort [x1, x2]
        [y1', y2'] = sort [y1, y2]

intersects v h =
    segmentY1 v <= segmentY1 h && segmentY1 h <= segmentY2 v &&
    segmentX1 h <= segmentX1 v && segmentX1 v <= segmentX2 h

main = do
    input ← openFile "input.txt" ReadMode

    let readWords = map read . words <$> hGetLine input

    [n] ← readWords
    ss ← replicateM n $ (\[x1, y1, x2, y2] → makeSegment x1 y1 x2 y2) <$> readWords

    let
        vs = [s | s ← ss, segmentX1 s == segmentX2 s]
        hs = [s | s ← ss, segmentY1 s == segmentY2 s]

        count v1 v2 = c * (c-1) `div` 2
            where
                c = length [h | h ← hs, intersects v1 h, intersects v2 h]

    withFile "output.txt" WriteMode (\handle →
        hPrint handle $ sum [count v1 v2 | (v1, v2s) ← zip vs (tail $ tails vs), v2 ← v2s])
