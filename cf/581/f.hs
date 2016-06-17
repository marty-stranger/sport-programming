import Data.List ((\\))
import qualified Data.Map as Map

data Vertex = Leaf | Node [Vertex] deriving (Show)

main = do
	getLine
	es <- (map ((\[u, v] -> (u, v)) . map read . words) . lines) `fmap` getContents

	let
		build es i = 
				if null children then Leaf else Node children
			where
				es1 = filter ((== i) . fst) es
				es2 = filter ((== i) . snd) es

				es' = (es \\ es1) \\ es2

				children = 
					(map (build es') $ map snd $ es1) ++
					(map (build es') $ map fst $ es2)

		tree = build es 1

		costs = 
			Map.fromList $ (
			
			

	
