{-# LANGUAGE UnicodeSyntax #-}

import Control.Applicative
import System.IO

solve n
	| n == 21 = 1
	| null ns = -1
	| otherwise = 2 + head ns `div` 14
	where
		ns = [n' | i ← [1..6], j ← [1..6], let n' = n - (21 - i) - (21 - j), n' >= 0, n' `mod` 14 == 0]

main = do
	input ← openFile "input.txt" ReadMode
	n ← read <$> hGetLine input

	output ← openFile "output.txt" WriteMode
	hPrint output $ solve n
	hClose output

