import Control.Applicative ((<$>))

import Data.Char (toLower)
import qualified Data.Map as Map
import Data.Tuple

main = do
	getLine
	pairs <- map ((\[to, _, from] -> (to, from)) . words) . lines . map toLower <$> getContents

	let distances =
			Map.fromList $ ("polycarp", 1) : (map (uncurry calc) pairs)
		where
			calc to from = (to, (distances Map.! from) + 1)


	print $ maximum $ map snd $ Map.toList distances

	
