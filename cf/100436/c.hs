import Control.Monad
import Data.List

radius [a, b, c] =
    (p - a) * (p - b) * (p - c) / p
  where
    p = (a + b + c) / 2

main = do
  n <- readLn
  ts <- replicateM n ((map read . words) `fmap` getLine)

  let rs = map radius ts

  print $ maximum $ map length $ group $ sort $ rs

  
