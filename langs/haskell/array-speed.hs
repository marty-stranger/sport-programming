{-# OPTIONS_GHC -O2 #-}
{-# LANGUAGE BangPatterns #-}

import Control.Applicative ((<$>))
import Control.Monad (forM, forM_, replicateM, foldM)
import Control.Monad.ST (runST, ST)

import Data.Array.Base (unsafeRead, unsafeWrite)
import Data.Array.ST
import Data.Array.Unboxed (UArray, (!), listArray)

import Data.List (foldl', foldr)

import Data.STRef

n :: Int
n = 100000000

foldM' :: (Monad m) => (a -> b -> m a) -> a -> [b] -> m a
foldM' _ z [] = return z
foldM' f z (x:xs) = do
  z' <- f z x
  z' `seq` foldM' f z' xs

sum' = foldr (+) 0

solve = runST $ do
	a <- newArray (0, n) 0 :: ST s (STUArray s Int Int)

	forM_ [0..n-1] $ \i ->
		unsafeWrite a i i

	s <- newSTRef 0
	forM_ [0..n-1] $ \i -> do
		v <- unsafeRead a i
  		modifySTRef' s (+ v)

	readSTRef s

	-- foldM' (\s i -> (s+) <$> (unsafeRead a i)) (0 :: Int) [0..n-1]
	
	-- sum' <$> (forM [0..n-1] $ \i -> unsafeRead a i)

main = do
	putStrLn $ show solve
