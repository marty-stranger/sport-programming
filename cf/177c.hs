import Control.Applicative
import Control.Monad
import Data.Array
import Data.Graph
import Data.Maybe
import Data.Tree
import Data.Tuple

readEdge = do
	[i, j] <- map read . words <$> getLine
	return (i, j)

unordered edges = edges ++ map swap edges

solve n friends dislikes =
		if null counts
			then Nothing
			else Just $ maximum counts
	where
		likes = accumArray (&&) True ((1, 1), (n, n)) $ map (\d -> (d, False)) $ unordered dislikes
		g = buildG (1, n) $ unordered friends
		cs = map flatten $ components g
		allLikes c = and [likes ! (i, j) | i <- c, j <- c]
		counts = map length $ filter allLikes cs

main = do
	n <- readLn
	m <- readLn
	friends <- replicateM m readEdge
	m2 <- readLn
	dislikes <- replicateM m2 readEdge
	let r = solve n friends dislikes
	if isJust r
		then print $ fromJust r
		else print 0
