import Control.Applicative
import Data.List

main = do
	getLine
	xs <- map read . words <$> getLine :: IO [Int]
	print $ (sum $ map ((`div` 2) . length) $ group $ sort xs) `div` 2

