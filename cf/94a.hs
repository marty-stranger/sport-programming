import Control.Monad
import Data.Maybe
import Data.List

chop s
	| null s = Nothing
	| otherwise = Just $ splitAt 10 s

main = do
	number <- getLine
	codes <- replicateM 10 getLine

	putStrLn $ foldl1 (++) $ map (show . fromJust . (`elemIndex` codes)) $ unfoldr chop number
	
