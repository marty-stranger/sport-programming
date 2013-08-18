zeroless = read . filter (/= '0') . show  

solve a b =
		zeroless c == zeroless a + zeroless b
	where
		c = a + b

main = do
	a <- readLn
	b <- readLn
	putStrLn $ if solve a b then "YES" else "NO"
