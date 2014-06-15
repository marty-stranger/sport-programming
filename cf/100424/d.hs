{- ok! -}
{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 #-}
import Control.Applicative ((<$>), (<*>))
import Control.Monad (replicateM, sequence)
import Data.Array.Unboxed (UArray, elems, listArray, (!))
import Data.Bits (complementBit, testBit, popCount, (.&.))
import Data.List (foldl1', transpose)

import Debug.Trace (trace)

main = do
  [n, m] <- map read . words <$> getLine
  template <- transpose <$> replicateM n getLine

  let
    templateA = (listArray ((1, 1), (m, n)) $ map conv $ concat template) :: UArray (Int, Int) Int
      where
        conv '.' = -1
        conv 'B' = 0
        conv 'G' = 1
        conv 'W' = 2

    solution
        | m == 1 = length . filter (`matches` (head template)) . 
           filter (\s -> and $ zipWith (/=) s (tail s)) . sequence $ replicate n "BGW" 

        | otherwise = foldl1' (+.) $ elems cs
      where
        cs = solve m n

        (+.) :: Int -> Int -> Int
        a +. b = (a + b) `rem` (10^9 + 7)
        infixl 6 +.

        matches :: String -> String -> Bool
        matches s t = and $ zipWith (\a b -> b == '.' || a == b) s t

        k = 2^n

        space = (,) <$> [0..2] <*> [0..k-1]
        build l = listArray (head space, last space) l :: UArray (Int, Int) Int

        check0 :: Int -> Int -> Int -> Int -> Bool
        check0 i j c m = 
            (take j colors) `matches` (take j $ template !! (i-1)) &&
              (drop j colors) `matches` (drop (j-1) $ template !! (i-2))
          where
            colors = map ("BGW" !!) . scanl (\c s -> (c + s + 1) `rem` 3) c $ bits n m
              where
                bits 0 m = []
                bits i m = m `rem` 2 : bits (i-1) (m `quot` 2)

        check i j c m = t == -1 || t == c'
          where
            m' = m .&. (2^(j-1) - 1)
            c' = (c + (popCount m') + j-1) `rem` 3
            t = templateA ! (i, j)

        solve 2 1 = build $ map compute space
          where
            compute (c, m) = if check0 2 1 c m then 1 else 0
        solve i 1 = build $ map compute space
          where
            !cs' = solve (i-1) n

            compute (c, m) = if check i 1 c m then compute' c m else 0
            compute' c m =
                cs' ! (c', m') +. cs' ! (c', m'')
              where
                m' = m `quot` 2
                c' = (c + (m `rem` 2) + 1) `rem` 3
                m'' = m' + 2^(n-1)

        solve i j = build $ map compute space
          where
            !cs' = solve i (j-1)

            t = templateA ! (i, j)

            check2 c m = t == -1 || t == c'
              where
                m' = m .&. (2^(j-1) - 1)
                c' = (c + (popCount m') + j-1) `rem` 3

            compute (c, m) = if check2 c m then compute' c m else 0
            compute' c m
                | b1 == b2 = cs' ! (c, m)
                | b1 /= b2 = cs' ! (c, m) +. cs' ! (c, m')
              where
                b1 = m `testBit` (j-2)
                b2 = m `testBit` (j-1)
                m' = m `complementBit` (j-2) `complementBit` (j-1)

  print solution
