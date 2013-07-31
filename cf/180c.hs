import Data.Char

main = do
	s <- getLine
	let cs = scanl (+) 0 $ map (fromEnum . isAsciiUpper) s
	print $ minimum $ map (\(i, c) -> (i-c) + ((last cs) - c)) $ zip [0..length s] cs
	
