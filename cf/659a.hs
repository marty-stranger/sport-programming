{- ok -}
main = do
	[n, a, b] <- (map read . words) `fmap` getLine
 	print $ (a - 1 + b) `mod` n + 1
