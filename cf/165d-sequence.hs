import Control.Applicative
import Control.Monad
import Debug.Trace
import Data.Array
import Data.Bits
import Data.Graph
import Data.List
import Data.Maybe
import Data.Sequence (Seq)
import qualified Data.Sequence as Seq
import Data.Tree
import Data.Tuple

type Fenwick = Seq Int

fenwick l = Seq.replicate l 0

update f i d
	| i < Seq.length f = update f' i' d
	| otherwise = f
	where
		f' = Seq.adjust (+ d) i f
		i' = i .|. (i + 1)
		
query f i
	| i >= 0 = Seq.index f i + query f i'
	| otherwise = 0
	where
		i' = (i .&. (i + 1)) -  1

unordered edges = edges ++ map swap edges

solve n edges queries =
		process fenwicks queries
	where
		g = buildG (1, n) (unordered edges)
		root = fromMaybe 1 $ find (\i -> indegree g ! i > 2) [1..n]
		paths = map flatten $ subForest $ head $ dfs g [root]

		parents = accumArray (flip const) 0 (1, n) $ concat [path `zip` (root:path) | path <- paths]

		places = accumArray (flip const) (0, -1) (1, n) $
			[(vertex, (pathIndex, index)) | (path,pathIndex) <- paths `zip` [0..],
				(vertex, index) <- path `zip` [0..]]

		edges' = listArray (1, length edges) edges
		edgesPlaces edgeIndex = places ! k
			where
				(i, j) = edges' ! edgeIndex
				k = if parents ! i == j then i else j

		fenwicks = Seq.fromList $ map (fenwick . length) paths

		process _ [] = []
		process fenwicks ([t, edgeIndex]:queries) =
				process fenwicks' queries
			where
				(fenwicksIndex, index) = edgesPlaces edgeIndex
				fenwick = fenwicks `Seq.index` fenwicksIndex
				fenwick' = update fenwick index (if t == 1 then -1 else 1)
				fenwicks' = Seq.update fenwicksIndex fenwick' fenwicks
		process fenwicks ([3, i, j]:queries) =
				d : process fenwicks queries
			where
				(i1, j1) = places ! i
				(i2, j2) = places ! j
				s1 = query (fenwicks `Seq.index` i1) j1
				s2 = query (fenwicks `Seq.index` i2) j2
				
				d = if i1 == i2
					then if s1 == s2 then abs (j1 - j2) else -1
					else if s1 + s2 == 0 then j1 + j2 + 2 else -1

main = do
	n <- readLn
	
	edges <- map ((\[a, b] -> (a, b)) . map read . words) <$> replicateM (n - 1) getLine
	m <- readLn
	let queries = []
	queries <- map (map read . words) <$> replicateM m getLine
	putStrLn $ unlines $ map show $ solve n edges queries
