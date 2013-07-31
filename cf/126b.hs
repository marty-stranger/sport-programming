{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 -optc-O3 #-}
import Data.Word

import qualified Data.ByteString as B

data Item = Item { next :: Item, prefix :: Item, ch :: Word8, k :: Int } | NilItem deriving (Eq)

build ind !i s 
	| s == B.empty = []
	| otherwise =
		Item (head is) i'' (B.head $ B.tail s) ind : is
	where
		c = B.head s
		i' = find i
		i'' = if ind /= 1 && ch i' == c then next i' else i'
		is = build (ind + 1) i'' (B.tail s)

		find !i
			| i' == NilItem || ch i == c = i
			| otherwise = find i'
			where i' = prefix i


main = do
	s1 <- B.getLine

	let	s = B.init s1

	let	i = Item (head is) NilItem (B.head s) 0
		is = build 1 i s
		ps = map (\i -> k $ prefix i) is

		n = B.length s

		p = ps !! (n-1)

	if p == 0
	then putStrLn "Just a legend"
	else
		let ps' = filter (== p) (init ps) in
			if ps' /= []
			then B.putStrLn $ B.take (head ps') s
			else
				let p' = ps !! (p - 1) in
				if p' == 0
				then putStrLn "Just a legend"
				else B.putStrLn $ B.take p' s
