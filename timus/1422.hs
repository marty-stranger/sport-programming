import Control.Applicative ((<$>))
import Data.List (sort, tails, group)

data Point = Point Double Double Double
data Vector = Vector Double Double Double deriving (Eq, Ord)

main = do
	getLine
	points <-  map ((\[x, y, z] -> Point x y z) . map read . words) . lines <$> getContents
	let result =
			maximum . map count . init $ tails points
		where
			count (p:[]) = 1
			count (p:ps) =
					(maximum . map length . group . sort $ map (normalize . (-. p)) ps) + 1
				where
					(Point x2 y2 z2) -. (Point x1 y1 z1) = Vector (x2 - x1) (y2 - y1) (z2 - z1)

					normalize v@(Vector x y z) =
							Vector (x' / m) (y' / m) (z' / m)
						where
							(Vector x' y' z') = if x < 0 || x == 0 && y < 0 || x == 0 && y == 0 && z < 0
								then Vector (-x) (-y) (-z)
								else v

							m = maximum [x', y', z']

	print result
