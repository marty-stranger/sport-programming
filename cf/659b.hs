{- ok -}
import Control.Applicative ((<$>))
import Data.List (groupBy, sortBy)
import Data.Function (on)
import Data.ByteString (getLine, getContents)
import Data.ByteString.Char8 (readInt, lines, words, unpack)
import Data.Maybe (fromJust)
import Prelude hiding (getLine, getContents, lines, words)

readInt' = fst . fromJust . readInt

main = do
	getLine
	people <- map ((\[a, b, c] -> (unpack a, readInt' b, readInt' c)) . words) . lines <$> getContents

	let
		select [(name1, _, _), (name2, _, _)] = name1 ++ " " ++ name2
		select ((name1, _, score1):(name2, _, score2):(name3, _, score3):_) = if score2 == score3 then "?" else name1 ++ " " ++ name2

	putStr . unlines . map (select . reverse) . groupBy ((==) `on` (\(_, a, _) -> a)) $ sortBy (compare `on` (\(a, b, c) -> (b, c))) people
 	
