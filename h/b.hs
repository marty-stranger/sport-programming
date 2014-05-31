{-# LANGUAGE BangPatterns, MagicHash #-}
{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}

import Control.Monad
import Control.Monad.ST
import qualified Data.Vector.Unboxed.Mutable as V
import Data.STRef

heapInit n = do
    lr <- newSTRef (0 :: Int)
    ps <- V.new n :: ST s (V.STVector s Int)
    vs <- V.new n :: ST s (V.STVector s Int)
    is <- V.new n :: ST s (V.STVector s Int)
    return (lr, ps, vs, is)

heapInsert h@(lr, ps, vs, is) k v = do
    l <- readSTRef lr
    modifySTRef' lr (+1)
  
    V.write ps l k
    V.write vs k v
    V.write is k l

heapUp h@(lr, ps, vs, is) i = do
  k <- V.unsafeRead ps i
  v <- V.unsafeRead vs k

  let update i
        | i == 0 = return 0
        | otherwise = do
          let j = (i - 1) `div` 2
 
          k' <- V.unsafeRead ps j
          v' <- V.unsafeRead vs k'

          if v < v' then do
            V.unsafeWrite ps i k'
            V.unsafeWrite is k' i
          else
            return ()

          update (i - 1)


  i' <- update i
  V.unsafeWrite ps i' k
  V.unsafeWrite is k i'

f = runST $ do
  let l = 10^6
  h <- heapInit l
  replicateM_ l $ heapInsert h 10 20

  forM_ [0..3*10^4] $ \i -> heapUp h (i `mod` l)

  return "ok"

main = do
  print f

