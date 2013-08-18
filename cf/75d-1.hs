{- TLE -}
import Control.Monad
import Data.Array

data Sums = Sums { sumsTotal :: Int, sumsLeft :: Int, sumsRight, sumsSub :: Int}

sums xs = Sums total left right sub
	where
		total = sum xs
		left = maximum $ scanl1 (+) xs
		right = maximum $ scanr1 (+) xs
		sub = maximum $ scanl1 (\s x -> max (s + x) x) xs

solve arrays indexes =
		maximum $ concat [map sumsSub sumss, ends, zipWith (+) (0:ends) $ map sumsLeft sumss]
	where
		arraysSums = listArray (1, length arrays) $ map sums arrays
		sumss = map (arraysSums !) indexes
		ends = tail $ scanl (\s (Sums total _ right _) -> max right $ s + total) 0 sumss

getWords = (map read . words) `fmap` getLine

main = do
	[n, m] <- getWords
	arrays <- replicateM n $ tail `fmap` getWords
	indexes <- getWords
	print $ solve arrays indexes

