import Control.Monad (replicateM_)

main = do
  t <- readLn

  replicateM_ t $ do
    [x, y, k, t] <- (map read . words) `fmap` getLine

    let
      solution
        | y == 1 = x + t
        | otherwise = solve x k t
        where
          solve x 0 t = x + t
          solve x k 0 | k > 0 && x `rem` y /= 0 = x + y - (x `rem` y)
          solve x k 0 | otherwise = x
          solve x k t =
              case r of
              0 -> solve (x + y*m) (k-m) (t-m)
              1 -> solve (x+y-1) (k-1) t
              _ | t >= d + 1 -> max (solve (x+d+1) k (t-d-1)) (solve (x+d) (k-1) t)
              _ | otherwise -> solve (x+d) (k-1) t
            where
              r = x `rem` y
              m = min k t
              d = y - r

    print solution
