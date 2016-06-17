import Control.Applicative ((<$>))
import Data.List (transpose)

main = do
	getLine
	a <- lines <$> getContents

	let b = dup . (map dup) $ transpose a
		where
			dup = concatMap (replicate 2)

	putStrLn $ unlines $ b
