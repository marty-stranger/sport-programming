{-# LANGUAGE UnicodeSyntax #-}

import Control.Applicative
import Data.Maybe

readWords = map read . words <$> getLine

solve n b as = 
		if any (\a → s < a * n) as
			then Nothing
			else Just $ map (\a → s/n - a) as
	where
		s = b + sum as

main = do
	[n, b] ← readWords
	as ← readWords

	let r = solve n b as
	if isNothing r
		then putStrLn "-1"
		else mapM_ print $ fromJust r
