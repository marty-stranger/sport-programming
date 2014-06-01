import Data.ByteString.Char8 (getLine, readInt, words)
import Data.Array (listArray, (!))
import Data.List (group, sort)
import Data.Maybe (fromJust)
import Prelude hiding (getLine, words)

import Debug.Trace (trace)

readInts = (map (fst . fromJust . readInt) . words) `fmap` getLine

main = do
  getLine
  as <- fmap sort readInts

  let
    solution = solve $ reverse $ as
      where
        solve (a:[]) = -1
        solve (a:c:[]) = -1
        solve (a:b:c:[]) = -1
        solve (a:b:c:d:as) = trace (show [a, b, c, d]) $ 
          if b + c + d > a && a /= d then a + b + c + d else solve (b:c:d:as)

  print solution
