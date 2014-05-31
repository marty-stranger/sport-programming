import Data.List (sort)

solve as bs =
    if and $ zipWith (>) as' bSums
      then "Dire victory"
      else "Redemption"
  where
    (as', bs') = unzip $ sort $ (zip as bs)
    bSums = scanl1 (+) bs'

readInts = (map read . words) `fmap` getLine

main = do
  [n] <- readInts
  as <- readInts
  bs <- readInts

  putStr $ solve as bs
