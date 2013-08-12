solve n d =
	if d*d <= n
		then if n `mod` d == 0
			then (n `div` d) + solve (n `div` d) d
			else solve n (d + 1)
		else if n == 1
			then 0
			else 1

main = do
	n <- readLn
	print $ n + solve n 2
