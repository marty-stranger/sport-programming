main = do
	getLine
	as <- (map read . words) `fmap` getLine

	let
		ms = tail (scanr1 max as) ++ [0]
		res = map (\(v, m) -> if v > m then 0 else m + 1 - v) $ zip as ms

	putStrLn $ unwords . map show $ res
