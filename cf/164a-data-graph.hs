import Control.Applicative
import Control.Monad
import Data.Array
import Data.Graph
import Data.List
import Data.Tuple
import qualified Data.Tree as Tree

data Action = Ignore | Assign | Use deriving (Enum, Eq)

getWords =  map read . words <$> getLine

solve actions edges =
		zipWith (&&) (visited g1 Assign) (visited g2 Use)
	where
		n = length actions
		actions' = listArray (1, n) actions

		visited g action =
				elems $ accumArray (||) False (1, n) $ zip indexes $ cycle [True]
			where
				indexes = concatMap Tree.flatten $ dfs g $ filter ((== action) . (actions' !)) [1..n]

		edges' = filter (\(i,j) -> actions' ! i /= Assign) $ map swap edges

		g1 = buildG (1, n) edges
		g2 = buildG (1, n) edges'

main = do
	[n, m] <- getWords
	vs <-  map 
	actions <- map toEnum <$> getWords
	-- edges <- replicateM m $ (\[x, y] -> (x, y)) <$> getWords
	edges <- map ((\[x, y] -> (x, y)) . map read . words) . lines <$> getContents

	let r = solve actions edges
	mapM_ print $ map fromEnum r
