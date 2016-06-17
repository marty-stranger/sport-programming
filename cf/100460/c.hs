{-
  на 11-м тесте работает около 10 секунда
  профалер показывает, что основной затык в heapUp
  толи на самом деле там аллоцируется много объектов (хаскелл не скатывается до примитивных типовщ)
  толи профалер сам влияет на показания

  изолированный тест обеждает, что эта штука может работать оптимально
-}

{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}

import Control.Applicative ((<$>))
import Control.Monad (forM, forM_, foldM, replicateM)
import Control.Monad.ST (runST, ST)
import Data.ByteString.Char8 (readInt, words, getLine)
import Data.List (sort)
import Data.Maybe (fromJust)

import qualified Data.Set as Set
import Data.STRef

import Data.Vector (Vector)
import qualified Data.Vector as Vector
import qualified Data.Vector.Unboxed as UVector
import qualified Data.Vector.Unboxed.Mutable as MVector

import Prelude hiding (getLine, readInt, words)

heapInit n = do
  lr <- newSTRef 0
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

  heapUp h l

heapUp h@(lr, ps, vs, is) i = do
  k <- MVector.read ps i
  v <- MVector.read vs k

  let
    update i
        | i == 0 = return 0
        | otherwise = do
          let j = (i - 1) `div` 2

          k' <- MVector.unsafeRead ps j
          v' <- MVector.unsafeRead vs k'
          if v < v' then do
            MVector.unsafeWrite ps i k'
            MVector.unsafeWrite is k' i
            update j
          else
            return i

  i' <- update i
  heapUpdate h k i'

{-
heapUp h@(lr, ps, vs, is) 0 = return ()
heapUp h@(lr, ps, vs, is) !i = do
  let j = (i - 1) `div` 2

  (k, v) <- heapRead h i
  (k', v') <- heapRead h j

  if v < v' then do
    MVector.unsafeSwap ps i j
    MVector.unsafeSwap is k k'
    heapUp h j
  else
    return () -}

{-# INLINE heapRead #-}
heapRead h@(lr, ps, vs, is) i = do
  k <- MVector.read ps i
  v <- MVector.read vs k
  return $ (k, v)

{-# INLINE heapUpdate #-}
heapUpdate h@(lr, ps, vs, is) k i = do
  MVector.unsafeWrite ps i k
  MVector.unsafeWrite is k i

heapDown h@(lr, ps, vs, is) i = do
  l <- readSTRef lr
  (k, v) <- heapRead h i

  let update i
        | 2*i + 1 >= l = return i
        | otherwise = do
          let j = 2*i + 1
          (k', v') <- heapRead h j

          j' <-
            if j + 1 < l then do
              (k'', v'') <- heapRead h (j + 1)
              return $ if v'' < v' then j + 1 else j
            else
              return j

          (k'', v'') <- heapRead h j'

          if v > v'' then do
            heapUpdate h k'' i
            update j'
          else
            return i

  i' <- update i
  heapUpdate h k i'

heapExtract h@(lr, ps, vs, is) = do
  k <- MVector.read ps 0
  l <- readSTRef lr
  k' <- MVector.read ps (l - 1)
  MVector.write ps 0 k'
  modifySTRef' lr (\v -> v - 1)
  heapDown h 0
  return k

heapDecrease h@(lr, ps, vs, is) k d = do
  v <- MVector.read vs k
  MVector.write vs k (v - d)
  i <- MVector.read is k
  heapUp h i

heapNull h@(lr, ps, vs, is) = do
  l <- readSTRef lr
  return $ l == 0

-- readInts = map read . words <$> getLine
readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

type Weight = Int
data Edge = Edge !Int !Int !Weight
data EdgeTo = EdgeTo !Int !Weight
type Graph = Vector [EdgeTo]

dijkstra graph = runST $ do
    distances <- MVector.replicate n (10^9 :: Int)
    MVector.write distances source 0

    queue <- heapInit n
    heapInsert queue 0 0
    forM_ [1..n-1] $ \i -> heapInsert queue i (10^9)

    let dijkstra' = do
        b <- heapNull queue
        if b then
          return ()
        else do
          u <- heapExtract queue
          du <- MVector.read distances u

          let es = graph Vector.! u
          forM_ es $ \(EdgeTo v w) -> do
            dv <- MVector.read distances v
            if du + w < dv then do
              MVector.write distances v (du + w)
              heapDecrease queue v (dv - du - w)
            else
              return ()

          dijkstra'

    dijkstra'
    distances' <- UVector.freeze distances
    return $ UVector.toList distances'
  where
    n = Vector.length graph
    source = 0

graph n edges = Vector.accum (flip (:)) empty edgesTo
  where
    empty = Vector.replicate n []
    edgesTo = map update $ edges ++ map reverse edges
      where
        update (Edge u v w) = (u, EdgeTo v w)
        reverse (Edge u v w) = Edge v u w

solve n edges =
    search 0 (length edges - 1)
  where
    weights = Vector.fromList $ sort $ map (\(Edge _ _ w) -> w) edges

    search l r
       | l >= r = if d > 10^9 then -1 else w
       | d > 1 = search (m + 1) r
       | otherwise = search l m
      where
        m = (l + r) `div` 2
        w = weights Vector.! m
        g = graph n $ map (\(Edge u v ew) -> Edge u v (if ew > w then 1 else 0)) edges
        d = last $ dijkstra g

main = do
  [n, m] <- readInts
  edges <- replicateM m readInts

  {-let g = graph n $ map (\[u, v, w] -> Edge (u-1) (v-1) w) edges
  print $ dijkstra g -}

  if m == 0 then
    print $ -1
  else
    print $ solve n $ map (\[u, v, w] -> Edge (u-1) (v-1) w) edges
