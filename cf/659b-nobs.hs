{- TLE 6 -}
import Control.Applicative ((<$>))
import Data.List (groupBy, sortBy)
import Data.Function (on)

main = do
	getLine
	people <- map ((\[a, b, c] -> (a, read b :: Int, read c :: Int)) . words) . lines <$> getContents

	let
		select [(name1, _, _), (name2, _, _)] = name1 ++ " " ++ name2
		select ((name1, _, score1):(name2, _, score2):(name3, _, score3):_) = if score2 == score3 then "?" else name1 ++ " " ++ name2

	putStr . unlines . map (select . reverse) . groupBy ((==) `on` (\(_, a, _) -> a)) $ sortBy (compare `on` (\(a, b, c) -> (b, c))) people
 	
