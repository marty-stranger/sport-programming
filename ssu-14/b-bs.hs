import Data.ByteString.Char8 (getLine, readInt, words)
import Data.List (sort)
import Data.Maybe (fromJust)
import Prelude hiding (getLine, words)

solve as bs =
    if and $ zipWith (>) as' bSums
      then "Dire victory"
      else "Redemption"
  where
    (as', bs') = unzip $ sort $ (zip as bs)
    bSums = scanl1 (+) bs'

readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

main = do
  [n] <- readInts
  as <- readInts
  bs <- readInts

  putStr $ solve as bs
