{- tle, brute force -}
import Control.Applicative ((<$>))
import Data.List (unfoldr)

main = do
  getLine
  as <- map (toRational . read) . words <$> getLine

  let
    solution = unfoldr next (1 / b)
      where
        a = foldr1 (\a s -> a + 1 / s) as
        b = 1 - a

        next 0 = Nothing
        next x = Just (x', 1 / x - (toRational x'))
          where
            x' = floor (1 / x)

  print $ length solution - 1
  putStrLn $ unwords $ map show $ solution
