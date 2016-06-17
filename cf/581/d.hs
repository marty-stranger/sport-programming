import Data.Maybe
import Data.List ((\\), find)
import Debug.Trace (trace)

main = do
	[x1, y1, x2, y2, x3, y3] <- (map read . words) `fmap` getLine

	let
		try [(x, y, c)] = [[(x, y, c)], [(y, x, c)]]
		try bs = concatMap next bs
			where 
				next b@(x, y, c) =
						(map ((x, y, c) :) bs') ++ (map ((y, x, c) :) bs')
					where
						bs' = try $ bs \\ [b]
				
		check [(x1, y1, c1), (x2, y2, c2), (x3, y3, c3)] = 
			x1 == x2 && x2 == x3 && y1 + y2 + y3 == x1 || x1 == x2 && y1 + y2 == y3 && x1 + x3 == y3

		opts = try [(x1, y1, 'A'), (x2, y2, 'B'), (x3, y3, 'C')]
		ans = find check opts

		printAns [(x1, y1, c1), (x2, y2, c2), (x3, y3, c3)] =
			if x1 == x2 && x2 == x3 && y1 + y2 + y3 == x1 then do
				print x1
				putStr $ unlines $ replicate y1 $ replicate x1 c1
				putStr $ unlines $ replicate y2 $ replicate x1 c2
				putStr $ unlines $ replicate y3 $ replicate x1 c3
			else  do
				print y3
				putStr $ unlines $ replicate y1 $ replicate x1 c1 ++ replicate x3 c3
				putStr $ unlines $ replicate y2 $ replicate x2 c2 ++ replicate x3 c3 

	if isNothing ans
		then print (-1)
		else printAns $ fromJust ans
