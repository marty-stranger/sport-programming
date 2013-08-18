import Data.Maybe

maybeMaximum [] = Nothing
maybeMaximum xs = Just $ maximum xs

solve a b queries =
		map process queries
	where
		d = gcd a b
		is = takeWhile (\i -> i*i <= d) [1..]
		ds = concat [[i, d `div` i] | i <- is, d `mod` i == 0]

		process (l, r) = maybeMaximum $ filter (\d -> l <= d && d <= r) ds

readWords = map read . words

main = do
	[a, b] <- readWords `fmap` getLine
	_ <- getLine
	queries <- (map ((\[a, b] -> (a, b)) . readWords) . lines) `fmap` getContents
	putStr $ unlines $ map (show . fromMaybe (-1)) $ solve a b queries

