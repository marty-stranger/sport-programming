import Data.Array
import Data.Bits
import Data.List
import Data.Maybe

solve :: [Int] -> [Maybe Int]
solve xs = map (compatibles !) xs
	where
		bits = 22 
		m = 2 ^ bits - 1
		starts = accumArray (||) False (0, m) $
			zip [complement x .&. m | x <- xs] $ repeat True

		compatibles = listArray (0, m) $ map try [0..m]
		try x
			| starts ! x = Just $ complement x .&. m
			| otherwise = listToMaybe $ catMaybes
				[compatibles ! (setBit x b) | b <- [0..bits - 1], not (testBit x b)]

solve' xs = [find (\y -> y .&. x == 0) xs | x <- xs]

main = do
	n <- readLn
	xs <- (map (read :: String -> Int) . words) `fmap` getLine
	putStrLn $ unwords $ map (show . fromMaybe (-1)) $ if n < 1000 then solve' xs else solve xs
