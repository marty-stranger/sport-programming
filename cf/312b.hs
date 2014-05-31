solve a b c d =
    p1 * (sum $ takeWhile (> 10**(-6)) $ iterate (* k) 1)
  where
    p1 = a / b
    k = (1 - p1) * (1 - c / d)

-- k + k^2 + ... = k / (1 - k)

solve' a b c d = 
    p1 * k / (1 - k)
  where
    p1 = a / b
    p2 = c / d
    k = (1 - p1) * (1 - p2)

main = do
  [a, b, c, d] <- (map read . words) `fmap` getLine
  print $ solve' a b c d
