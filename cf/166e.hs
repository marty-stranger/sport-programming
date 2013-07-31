-- tle. why? 
{-# LANGUAGE BangPatterns #-}                                                                                              
{-# OPTIONS_GHC -O3 -optc-O3 #-}
m :: Int
m = 10^9 + 7

a +. b = (a + b) `rem` m

{-#
solve a b c d 0 = d
solve !a !b !c !d !n =
	solve (b +. c +. d) (a +. c +. d) (a +. b +. d) (a +. b +. c) (n-1)
	
main = do
	n <- readLn
	print $ solve 0 0 0 1 n

#-}

iterate' :: (a -> a) -> a -> [a]
iterate' f x = x `seq` (x : iterate' f (f x))

f :: (Int, Int, Int, Int) -> (Int, Int, Int, Int)
f (a, b, c, d) = (b + c + d, a + c + d, a + b + d, a + b + c)

main = do
	n <- readLn
	print $ iterate' f (0, 0, 0, 1) !! n
