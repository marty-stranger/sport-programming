{-# OPTIONS_GHC -O2 #-}

import Control.Applicative ((<$>))
import Data.ByteString (getLine)
import Data.ByteString.Char8 (readInt, words)
import Data.List (foldl')
import Data.Maybe (fromJust, fromMaybe)
import qualified Data.IntMap as Map

import Prelude hiding (getLine, words)

readInt' = fst . fromJust . readInt

main = do
	as <- map readInt' . words <$> getLine

	let prevs =
			f 1 as [] Map.empty
		where
			f _ [] bs m = reverse bs 
			f i (a:as) bs m = f (i + 1) as (j:bs) m'
				where
					j = fromMaybe 0 $ Map.lookup a m
					m' = Map.insert a i m

	print $ foldl' (+) 0 prevs
