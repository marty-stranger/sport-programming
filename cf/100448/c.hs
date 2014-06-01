{- ok -}
import Control.Applicative ((<$>))
import Data.List (sort)

readInts = map read . words <$> getLine

main = do
  getLine
  as <- readInts

  let
    solution = find . reverse . sort $ as
      where
        find (a:as@(b:c:d:_))
          | b + c + d > a && d /= a = a + b + c + d
          | otherwise = find as
        find _ = -1

  print solution
