import Control.Applicative

solve' starts i prev [] = map (\j -> (j, i - 1)) starts
solve' starts i prev (x:xs)
	| x > prev = solve' (replicate (x - prev) i ++ starts) (i + 1) x xs
	| x < prev = map (\j -> (j, i - 1)) starts' ++ solve' starts'' (i + 1) x xs
	| x == prev = solve' starts (i + 1) prev xs
	where
		(starts', starts'') = splitAt (prev - x) starts

solve xs = solve' [] 1 0 xs

main = do
	getLine
	xs <- map read . words <$> getLine
	let r = solve xs
	print $ length r
	mapM_ putStrLn $ map (\(a, b) -> show a ++ " " ++ show b) r
