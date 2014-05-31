main = do
  [n, k] <- fmap (map read . words) getLine

  let
    s = sum [(product [1..i]) ^ k | i <- [0..n]] 
    last s = 
      if s `mod` 10 == 0 then last (s `div` 10) else s `mod` 10
  
  print $ last s
