import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.Array
import Data.Array.ST
import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Tuple

data Action = Ignore | Assign | Use deriving (Enum, Eq)

type Vertex = Int

type Graph = Array Vertex [Vertex]

reachable g vs = runST $ do
		bs <- newArray (bounds g) False :: ST s (STArray s Vertex Bool)
		mapM_ (search bs) vs
		getElems bs
	where
		search bs v = do
			b <- readArray bs v
			if b
				then return ()
				else do
					writeArray bs v True
					mapM_ (search bs) (g ! v)

getWords =  map (fst . fromJust . B.readInt) . B.words <$> B.getLine

build range edges = accumArray (flip (:)) [] range edges

solve actions edges =
		zipWith (&&) (reachable' g1 Assign) (reachable' g2 Use)
	where
		n = length actions
		actions' = listArray (1, n) actions

		reachable' g action = reachable g $ filter ((== action) . (actions' !)) [1..n]

		edges' = filter (\(i,j) -> actions' ! i /= Assign) $ map swap edges

		g1 = build (1, n) edges
		g2 = build (1, n) edges'

main = do
	[n, m] <- getWords
	actions <- map toEnum <$> getWords
	edges <- replicateM m $ (\[x, y] -> (x, y)) <$> getWords

	let r = solve actions edges
	mapM_ print $ map fromEnum r
