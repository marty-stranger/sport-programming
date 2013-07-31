import Control.Applicative

main = do
	[n, m] <- map read . words <$> getLine
	files <- replicateM n $ tail . map read . words <$> getLine
