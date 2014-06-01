import Control.Applicative ((<$>))
import Data.Array (listArray, (!))
import Data.List (sort)

main = do
  n <- readLn
  as <- listArray (1, n) . sort . map read . words <$> getLine

  let
    solution =
        min (cs0!n) (cs1!n)
      where
        d n = as!n - as!(n - 1)

        cs0 = listArray (0, n) $ map f [0..n]
          where
            f 0 = 0
            f 1 = 10^9
            f n = d n + min (cs0!(n - 2)) (cs1!(n - 2))

        cs1 = listArray (0, n) $ map f [0..n]
          where
            f 0 = 0
            f 1 = 10^9
            f n = d n + cs0!(n - 1)

  print solution
