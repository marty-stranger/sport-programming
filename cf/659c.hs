import Control.Applicative ((<$>))
import Data.List (sort)

main = do
	[n, m] <- map read . words <$> getLine
 	as <- map read . words <$> getLine

	let
 		res = find 1 (sort as) m
	   		where
				find i [] m
      					| i <= m = i : find (i + 1) [] (m - i)
					| otherwise = []
				find i (a:as) m
					| i > m = []
					| i == a = find (i + 1) as m
					| otherwise = i : find (i + 1) (a:as) (m - i)

	print $ length res
	putStr . unwords . map show $ res
