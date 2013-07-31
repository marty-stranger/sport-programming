import Control.Monad
import Data.Char
import Data.List
import System.IO

s2i = foldl (\a x -> 26*a + ord x - ord 'A' + 1) 0

i2s 0 = []
i2s a = chr (ord 'A' + (a - 1) `mod` 26) : (i2s $ (a - 1) `div` 26)

conv s =
	case groupBy (\a b -> isDigit a == isDigit b) s of
		[_, r, _, c] -> (reverse . i2s . read $ c) ++ r
		[c, r] -> "R" ++ r ++ "C" ++ (show . s2i $ c)

main = interact $ unlines . map conv . tail . lines
