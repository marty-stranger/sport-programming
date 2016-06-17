import Control.Applicative ((<$>))

main = do
	[w, h] <- map read . words <$> getLine
	a <- lines <$> getContents

	let b = [[a !! (y `div` 2) !! (x `div` 2) | y <- [0..2*h-1]] | x <- [0..2*w-1]]

	putStrLn $ unlines $ b
