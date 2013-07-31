import Control.Applicative
import Data.Graph
import Data.Int

_ ^. 0 = 1
a ^. b = fromIntegral (fromIntegral (a ^. (b - 1))) * (fromIntegral a) `rem` (10^9 + 7 :: Int64)

main :: IO ()
main = do
	[n, m, k] <- map read . words <$> getLine
	if k > n
	then
		print $ m ^. n
	else
		let
			g = buildG (1, n) [(s + d, s + k - 1 - d) | s <- [1..n+1-k], d <- [0..(k-1) `div` 2]]
		in
			print $ m ^. (length $ components g)