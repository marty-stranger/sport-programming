split x xs = split' xs
	where
		split' xs = xs' : if null xs'' then [] else split' $ tail xs''
			where
				(xs', xs'') = break (== x) xs

solve k s
	| k == 0 = sum $ map (\c -> c*(c-1) `div` 2) cs
	| otherwise = sum $ zipWith (*) cs $ drop k cs
	where
		cs = map fromIntegral . map ((+ 1) . length) $ split '1' s

main = do
	k <- readLn
	s <- getLine
	print $ solve k s
