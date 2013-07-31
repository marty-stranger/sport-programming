import Control.Applicative
import Control.Monad
import Data.Array
import Data.Int

data Point = Point Int64 Int64 deriving (Show)

instance Read Point where
	readsPrec _ s = [(Point x y, [])]
		where [x, y] = map read $ words s

data Vector = Vector Int64 Int64

Point x1 y1 `vector` Point x2 y2 = Vector (x2 - x1) (y2 - y1)

Vector x1 y1 `cross` Vector x2 y2 = x1*y2 - x2*y1

instance Eq Vector where
	u == v = u `cross` v == 0

instance Ord Vector where
	u `compare` v = u `cross` v `compare` 0

main = do
	n <- readLn
	ps <- listArray (1,n) <$> replicateM n readLn

	m <- readLn
	qs <- replicateM m readLn

	let
		isInside p =
				vs!2 < v && vs!n > v &&
					vs!l <= v && vs!(l+1) >= v && 
					ps!l `vector` (ps!(l+1)) < ps!l `vector` p
			where
				v = ps!1 `vector` p
				vs = (ps!1 `vector`) <$> ps

				find l r
					| l >= r = (l, r)
					| vs!m <= v = find m r
					| otherwise = find l (m-1)
					where m = (l+r+1) `div` 2
				(l, r) = find 1 (n-1)

	putStrLn $ if all isInside qs then "YES" else "NO"

