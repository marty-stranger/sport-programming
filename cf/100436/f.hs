{- ok -}
import Control.Applicative ((<$>))

main = do
  getLine
  (0:as) <- map read . words <$> getLine

  let
    solution = 0:bs
      where
        bs = case as of 
          [] -> []
          [2] -> [2]
          [a1] -> [1, a1 - 1]
          (1:a2:as) -> (1 + a2):as
          (a1:as) -> 1:(a1 - 1):as

  print $ length solution - 1
  putStrLn $ unwords $ map show $ solution
