-- runtime error on 26 !?
{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O3 -optc-O3 #-}

import Data.Array
import qualified Data.ByteString as B
import Data.List
import Data.Word

build s = elems l
	where
		n = B.length s
		l = listArray (1, n) (0 : (map f [2..n]))
		f i = if s `B.index` k == c then k + 1 else k
			where
				c = s `B.index`(i-1)
				k = head $ filter match $ iterate (l !) (l ! (i-1))
				match k = k == 0 || s `B.index` k == c

main = do
	ss <- B.getLine

	let
		s = B.init ss
--		s = ss
		ps = build s

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
