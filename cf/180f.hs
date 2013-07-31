-- tle 26
import Control.Applicative
import Control.Monad
import Data.Array

main = do
	n <- read <$> getLine
	[as, bs] <- replicateM 2 $ map read . words <$> getLine
	putStrLn $ unwords $ map show $ elems $ array (1, n) $ zip as bs
	
