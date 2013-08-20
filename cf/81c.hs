import Control.Applicative
import Data.List

readWords =  map read . words <$> getLine

solve a b marks
	| a == b = nums
	| a < b = map snd $ sort $ zip (map snd $ sort $ zip (map negate marks) [1..]) nums
	| a > b = map snd $ sort $ zip (map snd $ sort $ zip marks [1..]) nums
	where
		nums = replicate a 1 ++ replicate b 2

main = do
	_ <- getLine
	[a, b] <- readWords
	marks <- readWords
	putStrLn $ unwords $ map show $ solve a b marks
