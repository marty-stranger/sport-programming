import Data.List (sort)

main = do
	[n, k] <- (map read . words) `fmap` getLine
	as <- (map read . words) `fmap` getLine

	let
		r = sum $ map (`div` 10) as 
		sums = takeWhile (<= k) $ scanl1 (+) $ sort $ filter (/= 10) $ map (\a -> 10 - a `mod` 10) as
		r' = if null sums then 0 else length sums
		r'' = if null sums then k else k - (last sums)

		t = r + r' + (r'' `div` 10)

		ans = if t >= 10 * n then 10 * n else t

	print ans
