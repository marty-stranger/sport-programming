import Control.Monad (replicateM, replicateM_)

main = do
  t <- readLn

  replicateM_ t $ do
    n <- readLn
    a <- replicateM n $ (map read . words) `fmap` getLine

    let
      solution = hasZero || sameNearX || sameNearY
        where
          hasZero = elem 0 $ concat a
          sameNearX = any (\l -> or . zipWith (==) l $ tail l) a 
          sameNearY = or . concat . zipWith (zipWith (==)) a $ tail a

    putStrLn $ if solution then "YES" else "NO"
