{-# OPTIONS_GHC -O2 #-}

import Control.Applicative ((<$>))
import Control.Monad (forM, forM_, replicateM)
import Control.Monad.ST (runST, ST)

import qualified Data.Vector.Unboxed as UVector
import qualified Data.Vector.Unboxed.Mutable as MVector

import Data.List (foldl')

n :: Int
n = 100000000

foldM' :: (Monad m) => (a -> b -> m a) -> a -> [b] -> m a
foldM' _ z [] = return z
foldM' f z (x:xs) = do
  z' <- f z x
  z' `seq` foldM' f z' xs

solve = runST $ do
	a <- MVector.new n -- :: MVector.STVector s Int

	forM_ [0..n-1] $ \i ->
		MVector.unsafeWrite a i i

	-- foldl' (+) (0 :: Int) <$> (mapM (MVector.unsafeRead a) $ [0..n-1])
	foldM' (\s i -> (s+) <$> (MVector.unsafeRead a i)) (0 :: Int) [0..n-1]

main = do
	putStrLn $ show solve
