import Control.Applicative
import Data.Array

readWords = map read . words <$> getLine

solve n m c as bs =
		zipWith (+.) as $ zipWith (-.) (sums ++ replicate (n-m) (last sums)) (replicate (n-m+1) 0 ++ sums)
	where
		a +. b = (a + b) `mod` c
		a -. b = (a - b) `mod` c

		sums = scanl1 (+.) bs

main = do
		[n, m, c] <- readWords
		as <- readWords
		bs <- readWords
		putStrLn $ unwords $ map show $ solve n m c as bs
