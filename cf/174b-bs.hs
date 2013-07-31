{-# LANGUAGE UnicodeSyntax #-}

import Control.Applicative
import Data.Char
import Data.Maybe

import qualified Data.ByteString.Char8 as B

solve s =
		if length ss >= 2 &&
				(let l = B.length $ head ss in 1 <= l && l <= 8) &&
				(let l = B.length $ last ss in 1 <= l && l <= 3) &&
				all (\s → let l = B.length s in 2 <= l && l <= 11) (tail $ init ss)
			then Just $ recombine ss'
			else Nothing
			
	where
		ss = B.split '.' s
		ss' = head ss :
			(concat $ map (\s → let (a, b) = B.splitAt (min 3 $ B.length s - 1) s in [a, b]) $ tail $ init ss) ++
			[last ss]

		recombine [] = []
		recombine xs = (xs !! 0 `B.append` B.pack "." `B.append` (xs !! 1)) : (recombine $ tail $ tail xs)

trim = f . f
	where
		f = B.reverse . B.dropWhile isSpace

main = do
	s ← trim <$> B.getLine
	let r = solve s
	if isJust r
		then do
			putStrLn "YES"
			mapM_ B.putStrLn $ fromJust r
		else
			putStrLn "NO"
