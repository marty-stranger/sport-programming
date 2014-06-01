import Data.ByteString.Char8 (getLine, readInt, words)
import Data.Array (listArray, (!))
import Data.List (group, sort)
import Data.Maybe (fromJust)
import Prelude hiding (getLine, words)

import Debug.Trace (trace)

readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

main = do
  getLine
  tunes <- fmap sort readInts

  let
    solution = -- trace (show ds0) $ trace (show ds1) $
        min (ds0 ! n) (ds1 ! n)
      where
        n = length tunes
        as = listArray (1, n) tunes

        ds0 = listArray (0, n) $ map d0 [0..n]
        ds1 = listArray (0, n) $ map d1 [0..n]

        d0 0 = 0
        d0 1 = 10000000000
        d0 n = (as ! n) - (as ! (n-1)) + min (ds0 ! (n - 2)) (ds1 ! (n - 2))

        d1 0 = 0
        d1 1 = 10000000000
        d1 n = (as ! n) - (as ! (n-1)) + ds0 ! (n - 1)

  print solution
