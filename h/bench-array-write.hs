{-# LANGUAGE BangPatterns, UnboxedTuples, MagicHash #-}

import Control.Monad
import Control.Monad.ST
import Data.Array
import Data.Array.Base
import Data.Array.ST

import GHC.Prim
import GHC.Types

inc mbarr s =
    case readWord32Array# mbarr 0# s of
      (# s1, w0 #) ->
        writeWord32Array# mbarr 0# (w0 `plusWord#` 1##) s1

f = runST $ do
  let l = 10^6
  a <- newArray (0, l-1) 0 :: ST s (STUArray s Int Int)
  aa <- freeze a
  let (UArray _ _ _ ba) = aa
  -- forM_ [0..22*10^6] $ \i -> writeArray a (i `mod` l) i
  forM_ [0..10^6] $ \_ ->
    case inc (unsafeCoerce# ba) realWorld# of
      !s -> return ()
  return 5

main = do
  print $ f

