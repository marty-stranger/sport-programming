import Control.Applicative

below (x, y) (x', y') = x < x' && y == y'
rotate (x, y) = (-y, x)

solve ps =
		length $ filter supercentral ps
	where
		supercentral p = and [any (below p') ps' | (p', ps') <- take 4 $ zip (iterate rotate p) (iterate (map rotate) ps)]

main = do
	_ <- getLine
	ps <- map ((\[a,b] -> (a,b)) . map read . words) . lines <$> getContents
	print $ solve ps
