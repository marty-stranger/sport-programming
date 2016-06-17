{- ok -}
import Control.Applicative ((<$>))
import Data.Array (Array, (!))
import qualified Data.Array as Array
import Data.Set (Set)
import qualified Data.Set as Set
import Data.ByteString (getLine, getContents)
import Data.ByteString.Char8 (readInt, lines, words, unpack)
import Data.Maybe (fromJust)
import Data.Tuple (swap)

import Prelude hiding (getLine, getContents, lines, words)

readInt' = fst . fromJust . readInt

type Graph = Array Int [Int]

main = do
	[n, m] <- map readInt' . words <$> getLine
	edges <- map ((\[a, b] -> (a, b)) . map readInt' . words) . lines <$> getContents

	let 
		search set
     			| Set.null set = []
      			| otherwise = cycle:(search set')
       			where
		  		(cycle, set') = dfs set (Set.findMin set) 0

				dfs set u w = dfs' (u `Set.delete` set) $ filter (/= w) $ g ! u
    					where
		 				dfs' set [] = (False, set)
		 				dfs' set (v:vs) 
							| v `Set.notMember` set = (True, set)
						        | otherwise = (cycle1 || cycle2, set'')
		    					where
							   (cycle1, set') = dfs set v u
							   (cycle2, set'') = dfs' set' vs 

                                -- above is prettier ?
				-- dfs set u w = foldl dfs' (False, vs') . filter (/= w) $ g ! u
				--	where
	     			--		vs' = u `Set.delete` vs

				--		dfs' (f, vs) v
				--			| v `Set.notMember` vs = (True, vs)
				--		        | otherwise = (f || f', vs')
       				--			where
				--			      (f', vs') = dfs vs v u

	 	comps = search $ Set.fromList [1..n]	
		g = Array.accumArray (flip (:)) [] (1, n) $ edges ++ map swap edges

 	print . length . filter not $ comps

	

