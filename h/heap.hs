{-# LANGUAGE BangPatterns, MagicHash #-}
{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}

import Control.Monad
import Control.Monad.ST
import qualified Data.Vector.Unboxed.Mutable as MVector
import Data.STRef

heapInit n = do
  lr <- newSTRef (0 :: Int)
  ps <- MVector.new n :: ST s (MVector.STVector s Int)
  vs <- MVector.new n :: ST s (MVector.STVector s Int)
  is <- MVector.new n :: ST s (MVector.STVector s Int)
  return (lr, ps, vs, is)

heapInsert h@(lr, ps, vs, is) k v = do
  l <- readSTRef lr
  modifySTRef' lr (+1)

  MVector.write ps l k
  MVector.write vs k v
  MVector.write is k l

  -- heapUp h l

heapUp h@(lr, ps, vs, is) i = do
  k <- MVector.unsafeRead ps i
  v <- MVector.unsafeRead vs k
  
  let
    update i
        | i == 0 = return 0
        | otherwise = do
          let j = (i - 1) `div` 2
          k' <- MVector.unsafeRead ps j
          v' <- MVector.unsafeRead vs k'
          MVector.unsafeWrite ps i v'
          MVector.unsafeWrite ps i k'
          MVector.unsafeWrite is k' i

          update j

  i' <- update i
  MVector.unsafeWrite ps i' k
  MVector.unsafeWrite is k i'

f = runST $ do
  let l = 10^6
  h <- heapInit l
  replicateM_ l $ heapInsert h 10 20
  forM_ [0..3*10^6-1] $ \i -> heapUp h (i `mod` l)
  return "ok"

main = do
  print f
