main = do
  [n, k] <- (map read . words) `fmap` getLine
  if k >= n*(n-1) `div` 2
  then
    putStrLn "no solution"
  else
    putStr $ unlines $ map (\i -> "0 " ++ (show i)) $ take n $ [0..]
