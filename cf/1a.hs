main = do
	[n, m, a] <- fmap (map read . words) getLine
	print $ ceiling (n / a) * ceiling (m / a)
