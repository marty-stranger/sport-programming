import Data.Char
import Data.List

fix [] = []
fix (c:s) | isDigit c = c:fix s
fix (' ':cs)
		| rest /= [] && isDigit (head rest) = ' ':fix rest
		| otherwise = fix rest
	where
		rest = dropWhile (== ' ') cs
fix (',':cs)
		| rest /= [] && head rest /= '.' = ',':' ':fix rest
		| otherwise = ',':fix rest
	where
		rest = dropWhile (== ' ') cs
fix ('.':'.':'.':cs) =
		' ':'.':'.':'.':(fix rest)
	where
		rest = dropWhile (== ' ') cs

solve = dropWhile (== ' ') . fix . dropWhileEnd (== '\n')

main = interact solve
