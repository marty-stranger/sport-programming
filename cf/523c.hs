main = do
	s <- getLine
	t <- getLine

	let
		answer = if l <= r then r - l else 0
			where
				l = find s t
				r = length t - (find (reverse s) (reverse t)) + 1

				find s t = find' s t 0
					where
						find' "" _ i = i
						find' _ "" i = i
						find' (c:s) (d:t) i =
							if c == d
								then find' s t (i + 1)
								else find' (c:s) t (i + 1)

	print answer
