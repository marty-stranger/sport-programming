import Control.Monad (replicateM)
import Data.List

detect s 
    | f1 && not f2 = "Rainbow's"
    | not f1 && f2 = "Freda's"
    | otherwise = "OMG>.< I don't know!"
  where
    f1 = isPrefixOf "miao." s
    f2 = isSuffixOf "lala." s

main = do
  n <- readLn
  ss <- replicateM n getLine
  putStrLn $ unlines $ map detect ss
