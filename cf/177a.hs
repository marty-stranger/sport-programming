import Control.Applicative

-- NOTE doing the same via monad is slower than this! 
-- http://www.reddit.com/r/haskell/comments/oolyt/why_are_guards_in_the_list_comprehension_faster/
solve n xs =
	sum $ [x | (i, l) <- zip [1..n] xs, (j, x) <- zip [1..n] l, i == j || i == n+1-j || i == n `div` 2 + 1 || j == n `div` 2 + 1]

main = do
	n <- readLn
	a <- map (map (read :: String -> Int) . words) . lines <$> getContents
	print $ solve n a
