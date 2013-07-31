{-# LANGUAGE UnicodeSyntax #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}
import Control.Applicative
import Data.Array
import Data.Int

modulo :: Int
modulo = 10^9 + 7

a +. b = (a + b) `mod` modulo

build k = a
	where
		a = listArray (0, k) [listArray (0, k) [count' i j | j ← [0..k]] | i ← [0..k]]
		count' i j
			| j == 0 = 1
			| j <= i = (a ! (i-1) ! (j-1)) +. (a ! (i-1) ! j)
			| otherwise = 0

main = do
	[n, m, k] ← map read . words <$> getLine
	let a = build $ (max n m) - 1

	let c1 = if 2*k <= n-1 then a ! (n-1) ! (2*k) else 0
	let c2 = if 2*k <= m-1 then a ! (m-1) ! (2*k) else 0

	print $ (fromIntegral c1) * (fromIntegral c2) `mod` (fromIntegral modulo :: Int64)
