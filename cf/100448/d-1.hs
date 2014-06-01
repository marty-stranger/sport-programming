{- tle 6 -}
{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}
import Data.Array.Base (unsafeRead, unsafeWrite)
import Data.Array.MArray (newArray_)
import Data.Array.ST (STUArray)
import Data.Bits (xor)
import Data.ByteString.Char8 (getLine, readInt, words)
import Control.Monad (forM_)
import Control.Monad.ST (ST, runST)
import Data.Int (Int64)
import Data.Maybe (fromJust)
import Prelude hiding (getLine, words)

import Debug.Trace (trace)

readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

(+.) :: Int64 -> Int64 -> Int64
a +. b = (a + b) `mod` (10^9 + 7)
infixl 6 +.

main = do
  getLine
  as <- readInts

  let
    m = 2^14
    solution = runST $ do
      cs1 <- newArray_ (0, m - 1) :: ST s (STUArray s Int Int64)
      unsafeWrite cs1 0 1

      cs2 <- newArray_ (0, m - 1) :: ST s (STUArray s Int Int64)

      forM_ as $ \a -> do
        forM_ [0..m-1] $ \i -> do
          c1 <- unsafeRead cs1 i
          c2 <- unsafeRead cs1 (i `xor` a)
          unsafeWrite cs2 i $ c1 +. 2 * c2

        forM_ [0..m-1] $ \i -> do
          v <- unsafeRead cs2 i
          unsafeWrite cs1 i v

      unsafeRead cs1 0

  print solution
