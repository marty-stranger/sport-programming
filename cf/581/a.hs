main = do
	[a, b] <- (map read . words) `fmap` getLine

	let 
		n1 = min a b
		n2 = (b - n1 + a - n1) `div` 2
	putStrLn $ show n1 ++ " " ++ show n2
