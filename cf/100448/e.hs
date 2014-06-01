import Data.Bits (testBit, shift, (.|.))
import Data.Int (Int64)

main = do
  getLine
  as <- (map read . words) `fmap` getLine

  let
    solution = try (1 :: Int64) 0 0
      where
        try mask last count
            | cover = count
            | count == 5 = 6
            | last >= 50 = 6
            | otherwise =
              minimum $ [try (mask' i) i (count + 1) | i <- [last+1..50]]
          where
            cover = and $ map (mask `testBit`) $ as
            mask' i = mask .|. (mask `shift` i)

  print solution
