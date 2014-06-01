{- ok -}

main = do
  [n, k] <- fmap (map read . words) getLine

  let
    primes = [a | a <- [2..n], all ((/= 0) . mod a) [2..a-1]]
    sums = map (+1) $ zipWith (+) primes (tail primes)
    
    solution =
        (length $ filter try primes) >= k
      where
        try i = any (== i) sums

  putStrLn $ if solution then "YES" else "NO"

