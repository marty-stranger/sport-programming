{-# LANGUAGE BangPatterns #-}

import Data.Text (words)
import Data.Text.IO (getLine)
import Data.Text.Read (decimal)
import Data.List (foldl1')
import Data.Maybe (fromMaybe)
import Prelude hiding (getLine, words)

lcm' :: Int -> Int -> Int
lcm' !x !y = min (2 * 10^9) (x * y `div` (gcd x y))

solve :: [Int] -> Int -> [Maybe Int]
solve periods m =
    map solve' excepts
  where
    all = foldl1' lcm' periods
    lefts = scanl1 lcm' periods
    rights = scanr1 lcm' periods
    excepts = map (uncurry lcm') $ zip (1 : lefts) (tail rights ++ [1])

    solve' p 
        | p == all = Nothing
        | s > 10^9 = Nothing
        | otherwise = Just s
      where
        t = p * ((m + p - 1) `div` p)
        t' = if t `mod` all == 0 then t + p else t
        s = t' - m

-- readWords = (map read . words) `fmap` getLine
readInts = (map ((\(Right a) -> fst a) . decimal) . words) `fmap` getLine :: IO [Int]

main = do
  [n, m] <- readInts
  ts <- readInts
 
  let rs = solve ts m

  putStr $ unlines $ map (fromMaybe "Never" . fmap show) rs
