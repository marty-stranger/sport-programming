{-# LANGUAGE UnicodeSyntax #-}

import Control.Applicative
import Data.Maybe

split x xs = split' xs
	where
		split' xs = xs' : if null xs'' then [] else split' $ tail xs''
			where
				(xs', xs'') = break (== x) xs

between a b c = a <= c && c <= b

solve s =
		if length ss >= 2 &&
				(between 1 8 $ length $ head ss) &&
				(between 1 3 $ length $ last ss) &&
				all (between 2 11 . length) (tail $ init ss)
			then Just $ join $ [head ss] ++ (concatMap splitJoined $ tail $ init ss) ++ [last ss]
			else Nothing
			
	where
		ss = split '.' s

		splitJoined s = [a, b]
			where
				(a, b) = splitAt (min 3 $ length s - 1) s
				
		join [] = []
		join (x:y:xs) = (x ++ "." ++ y) : join xs

main = do
	s ← getLine
	let r = solve s
	if isJust r
		then do
			putStrLn "YES"
			mapM_ putStrLn $ fromJust r
		else
			putStrLn "NO"
