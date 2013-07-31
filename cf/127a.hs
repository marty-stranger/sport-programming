getWords = fmap (map read . words) getLine 

dist (x1, y1) (x2, y2) = sqrt $ (x2-x1)**2 + (y2-y1)**2

readPair = (\[x, y] -> (x, y)) . map read . words

main = do
	[_, k] <- getWords
	ps <- fmap (map readPair . lines) getContents
	let l = sum $ zipWith dist ps (tail ps)
	print $ k*l/50
