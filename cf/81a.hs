solve s = solve' s []
	where
		solve' [] stack = reverse stack
		solve' (x:xs) stack
			| not (null stack) && head stack == x = solve' xs $ tail stack
			| otherwise =  solve' xs $ x:stack

main = interact solve
