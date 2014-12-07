import Data.ByteString.Char8 (readInt, words, getLine)
import Data.Maybe (fromJust)
import Data.Vector ((!))
import qualified Data.Vector as Vector
import Prelude hiding (getLine, words)

solve as bs ds ts =
    map (uncurry solve') $ zip ds ts
  where
    as' = Vector.fromList $ scanl1 max as
    bs' = Vector.fromList $ scanl1 max bs

    search as v = if as ! i > v then i else l
      where
        search' l r 
          | l == r = l
          | as ! m > v = search' l m
          | otherwise = search' (m + 1) r
          where m = (l + r) `div` 2
        l = Vector.length as
        i = search' 0 (l - 1)

    solve' d s =
        case compare i j of
          LT -> "Mike"
          GT -> "Constantine"
          EQ -> "Draw"
      where
        i = search as' d
        j = search bs' s

readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

main = do
  [n] <- readInts
  as <- readInts
  bs <- readInts
  [m] <- readInts
  ds <- readInts
  ts <- readInts
 
  let rs = solve as bs ds ts

  putStr $ unlines rs
