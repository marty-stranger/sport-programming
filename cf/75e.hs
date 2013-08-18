import Control.Applicative
import Data.Function
import Data.List

data Point = Point Double Double deriving (Eq)
data Segment = Segment { segmentStart, segmentEnd :: Point } deriving (Eq)
data Vector = Vector Double Double

getWords = map read . words <$> getLine

splitEvery n = unfoldr $ \xs -> if null xs then Nothing else Just $ splitAt n xs
getPoints = map (\[a, b] -> Point a b) . splitEvery 2 <$> getWords

cross (Vector x1 y1) (Vector x2 y2) = x1*y2 - x2*y1
dot (Vector x1 y1) (Vector x2 y2) = x1*x2 + y1*y2
sub (Point px py) (Point qx qy) = Vector (qx - px) (qy - py)

intersects s@(Segment p1 p2) t@(Segment p3 p4) =
		(d1 > 0 && d2 < 0 || d1 < 0 && d2 > 0) &&
		(d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0) ||
		d1 == 0 && onSegment p1 t ||
		d2 == 0 && onSegment p2 t ||
		d3 == 0 && onSegment p3 s ||
		d4 == 0 && onSegment p4 s
	where
		direction p q r = sub p r `cross` sub p q

		onSegment (Point rx ry) (Segment (Point px py) (Point qx qy)) =
			min px qx <= rx && rx <= max px qx &&
			min py qy <= ry && ry <= max py qy

		d1 = direction p3 p4 p1
		d2 = direction p3 p4 p2
		d3 = direction p1 p2 p3
		d4 = direction p1 p2 p4

data Line = Line Point Point

onLine r (Line p q) = sub p q `cross` sub p r == 0

intersectsRay s@(Segment p1 p2) t@(Segment p3 p4) =
	intersects s t && not (p3 `onLine` Line p1 p2)

intersection s@(Segment sa sb) t@(Segment ta tb) = 
		sa `add` (c `mult` (sa `sub` sb))
	where
		mult a (Vector x y) = Vector (a * x) (a * y)
		add (Point px py) (Vector vx vy) = Point (px + vx) (py + vy)
		c = (sub sa ta `cross` sub ta tb) / (sub sa sb `cross` sub ta tb)

distance (Point px py) (Point qx qy) = sqrt $ (qx - px) ** 2 + (qy - py) ** 2

solve start end polygon
		| length intersecting < 2 = start `distance` end
		| otherwise =
			start `distance` i1 +
			minimum [distThrough, distAround1, distAround2] +
			i2 `distance` end
	where
		startEnd = Segment start end
		segments = zipWith Segment polygon $ tail polygon ++ [head polygon]

		intersecting = filter (startEnd `intersectsRay`) segments
		intersections = map (intersection startEnd) intersecting

		(s1,i1):(s2,i2):_ = sortBy (compare `on` (distance start . snd)) $
				intersecting `zip` intersections

		distThrough = 2 * (i1 `distance` i2)

		distAround s1 s2 segments = sum $ map (\(Segment p q) -> p `distance` q) $
			takeWhile (/= s2) $ tail $ dropWhile (/= s1) $ segments ++ segments

		distAround1 = 
			i1 `distance` segmentEnd s1 +
			distAround s1 s2 segments +
			segmentStart s2 `distance` i2

		distAround2 = 
			i1 `distance` segmentStart s1 +
			distAround s1 s2 (reverse segments) +
			segmentEnd s2 `distance` i2

main = do
	[start, end] <- getPoints
	_ <- getLine
	polygon <- getPoints
	print $ solve start end polygon

