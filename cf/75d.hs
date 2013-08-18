import Control.Monad
import Data.Array
import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Int

data Sums = Sums { sumsTotal, sumsLeft, sumsRight, sumsSub :: Integer }

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

getInts = (map (fst . fromJust . B.readInt) . B.words) `fmap` B.getLine
getIntegers = (map (fst . fromJust . B.readInteger) . B.words) `fmap` B.getLine

main = do
	[n, m] <- getInts
	arrays <- replicateM n $ tail `fmap` getIntegers
	indexes <- getInts
	print $ solve arrays indexes

