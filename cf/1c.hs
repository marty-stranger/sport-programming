import Control.Monad

data Vector = Vector Double Double
data Point = Point Double Double

eps = 1e-3
instance Eq Point where
	(Point x1 y1) == (Point x2 y2) = (abs (x1 - x2)) < eps && (abs (y1 - y2)) < eps

getPoint = do
	l <- getLine
	let [x, y] = map read (words l)
	return (Point x y)

vector (Point x1 y1) (Point x2 y2) = Vector (x2 - x1) (y2 - y1)
normal (Vector x y) = Vector (-y) x 
cross (Vector x1 y1) (Vector x2 y2) = x1*y2 - x2*y1
add' (Point x1 y1) (Vector x2 y2) = Point (x1 + x2) (y1 + y2)
div' (Vector x y) f = Vector (x / f) (y / f) 
mul' (Vector x y) f = Vector (x * f) (y * f)
sub' (Point x1 y1) (Point x2 y2) = Point (x1 - x2) (y1 - y2)

rotate (Point x y) a = Point (x * cos a - y * sin a) (x * sin a + y * cos a)

match n ps =
	let p = head ps
	in length (filter (\p -> p `elem` ps) [rotate p (2*pi*i / n) | i <- [0..n-1]]) == length ps

center p1 p2 p3 =
	let 
		an = normal (vector p1 p2)
		b = vector p2 p3
		bn = normal b
		c = vector p1 p3
		s = (an `cross` c) / (bn `cross` an)
	in
		p2 `add'` (b `div'` 2) `add'` ((bn `div'` 2) `mul'` s)

main = do
	[p1, p2, p3] <- replicateM 3 getPoint

	let
		p0 = center p1 p2 p3
		-- ps = map (\p -> p `sub'` p0) [p1, p2, p3]
		ps = map (sub' p0) [p1, p2, p3]
		n = head (filter (\n -> match n ps) [3..100])
		rr = x*x + y*y  where Point x y = ps !! 0

	print $ n*rr*sin(2*pi/n) / 2


