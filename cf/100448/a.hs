{- ok -}
import Data.List (permutations)

try [] s = s
try (a:as) s =
  maximum $ map ((try as) . read) $ permutations $ show $ s + a

main = do
  getLine
  as <- fmap (map read . words) getLine

  putStrLn $ show $ try as 0
