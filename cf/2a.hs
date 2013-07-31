import Data.List

data Round = Round String Int deriving (Show)

solve rs =
	let m =
--		maximum map (sum . map (\(Round _ s) -> s))
		groupBy (\(Round n1 _) (Round n2 _) -> n1 == n2)
			(sortBy (\(Round n1 _) (Round n2 _) -> n1 `compare` n2) rs)

	in show m

-- main = interact $ solve . map (\[n,i] -> Round (read n) (read i)) . map words . tail . lines

main =
	line <- getLine
	line2 <- getLine
	print map (\[n,i] -> Round (read n) (read i)) line
