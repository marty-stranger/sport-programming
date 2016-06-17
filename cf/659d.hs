{- ok -}
import Control.Applicative ((<$>))

main = do
	getLine
	points <- map ((\[a, b] -> (a, b)) . map read . words) . lines <$> getContents

	let
  		count = length $ filter (<0) $ zipWith mul vects $ tail vects ++ [head vects]
    			where
				vects = zipWith (\(x1, y1) (x2, y2) -> (x2 - x1, y2 - y1)) points $ tail points
				mul (x1, y1) (x2, y2) = x2 * y1 - x1 * y2

	print count

