{- tle 7 -}
{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O2 -optc-O2 #-}
import Data.Array.Base (unsafeRead, unsafeWrite)
import Data.Array.MArray (newArray_)
import Data.Array.ST (STUArray)
import Data.Bits (xor)
import Data.ByteString.Char8 (getLine, readInt, words)
import Control.Monad (forM_)
import Control.Monad.ST (ST, runST)
import Data.Maybe (fromJust)
import Prelude hiding (getLine, words)

import Debug.Trace (trace)

readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

(+.) :: Int -> Int -> Int
a +. b = (a + b) `mod` (10^9 + 7)
infixl 6 +.

main = do
  getLine
  as <- readInts

  let
    m = 2^14
    solution = runST $ do
      cs1 <- newArray_ (0, m - 1) :: ST s (STUArray s Int Int)
      unsafeWrite cs1 0 1

      cs2 <- newArray_ (0, m - 1) :: ST s (STUArray s Int Int)

      forM_ (zip as $ cycle [0, 1])$ \(a, i) ->
        if i == 0
          then do
            forM_ [0..m-1] $ \i -> do
              c1 <- unsafeRead cs1 i
              c2 <- unsafeRead cs1 (i `xor` a)
              unsafeWrite cs2 i $ c1 +. c2 +. c2
          else do
            forM_ [0..m-1] $ \i -> do
              c1 <- unsafeRead cs2 i
              c2 <- unsafeRead cs2 (i `xor` a)
              unsafeWrite cs1 i $ c1 +. c2 +. c2

      if (length as) `mod` 2 == 0
        then unsafeRead cs1 0
        else unsafeRead cs2 0

  print solution
