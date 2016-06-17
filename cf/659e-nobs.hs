{- tle 10 -}
import Control.Applicative ((<$>))
import Data.Array (Array, (!))
import qualified Data.Array as Array
import Data.Set (Set)
import qualified Data.Set as Set
import Data.Tuple (swap)

type Graph = Array Int [Int]

main = do
	[n, m] <- map read . words <$> getLine
	edges <- map ((\[a, b] -> (a, b)) . map read . words) . lines <$> getContents

	let 
		search vs 
     			| Set.null vs = []
      			| otherwise = f : (search vs')
       			where
		  		(f, vs') = dfs vs (Set.findMin vs) (-1)
      					where
		  				u = Set.findMin vs

				dfs vs u w
					| u `Set.notMember` vs = (True, vs')
			   	        | otherwise = foldl next (False, vs') $ filter (/= w) $ g ! u
		    			where
		 				vs' = u `Set.delete` vs

       						next (f, vs) v = (f || f', vs')
		     					where
		    						(f', vs') = dfs vs v u

	 	comps = search $ Set.fromList [1..n]	
		g = Array.accumArray (flip (:)) [] (1, n) $ edges ++ map swap edges

 	print . length . filter not $ comps

	

