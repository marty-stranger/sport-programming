import Data.List (permutations)

try :: Integer -> [Integer] -> Integer
try s [] = s
try s (a:as) =
    maximum $ map (\s -> try s as) ps
  where
    ps = map read $ permutations $ show $ s + a

main = do
  getLine
  as <- fmap (map read . words) getLine

  putStrLn $ show $ try 0 as
