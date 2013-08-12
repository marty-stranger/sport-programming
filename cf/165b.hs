solve n k = search 1 n
	where
		search l r 
			| l >= r = l
			| s >= n = search l m
			| s < n = search (m + 1) r
			where
				m = (l + r) `div` 2
				s = sum $ takeWhile (/= 0) $ iterate (`div` k) m

main = do
	[n, k] <- (map read . words) `fmap` getLine
	print $ solve n k
