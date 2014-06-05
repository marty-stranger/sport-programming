{- tle 6 -}
{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}
import Data.Array.Unboxed (listArray, (!), UArray)
import Data.Bits (xor)
import Data.Int (Int64)

(+.) :: Int64 -> Int64 -> Int64
a +. b = (a + b) `mod` (10^9 + 7)
infixl 6 +.

main = do
  getLine
  as <- (map read . words) `fmap` getLine

  let
    solution =
        solve as (listArray (0, 16383) $ 1 : repeat 0 :: UArray Int Int64)
      where
        solve [] cs = cs ! 0
        solve (a:as) !cs = solve as cs'
          where
            cs' = listArray (0, 16383) $ map f [0..16383] :: UArray Int Int64
              where
                f :: Int -> Int64
                f d = (cs ! d) +. ((cs ! (d `xor` a)) * 2)

  print solution
