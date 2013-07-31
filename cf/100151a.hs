{-# LANGUAGE UnicodeSyntax #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}

import Control.Applicative
import Control.Monad
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C
import Data.Function
import Data.List
import Data.Maybe
import Text.Printf
import System.IO

data Bank = Bank { bankX :: !Int, bankW :: !Int } deriving (Eq)

instance Ord Bank where
	compare = compare `on` bankW

data Result = Result { resultBank1 :: Bank, resultBank2 :: Bank }

instance Eq Result where 
	r1 == r2 = compare r1 r2 == EQ

instance Ord Result where
	(Result b1 b2) `compare` (Result b3 b4) = (bankW b1 + bankW b2) `compare` (bankW b3 + bankW b4)

hGetInts h = map (fst . fromJust . C.readInt) . C.words <$> B.hGetLine h

main = do
	input ← openFile "input.txt" ReadMode
	[n, d] ← hGetInts input
	banks ← replicateM n $ (\[x, w] → Bank x w) <$> hGetInts input

	let
		find b1 bs1 (b2:bs2) = if null bs2 then r else max r (find b1' bs1'' bs2)
			where
				(bs1', bs1'') = span (\b → bankX b + d <= bankX b2) bs1

				b1' = maximum (b1:(map Just bs1'))

				r = if isNothing b1' then Nothing else Just $ Result (fromJust b1') b2

		result = find Nothing banks banks

	output ← openFile "output.txt" WriteMode
	if isNothing result 
	then hPutStrLn output "-1 -1"
	else hPrintf output "%d %d" (fromJust (resultBank1 (fromJust result) `elemIndex` banks) + 1) (fromJust (resultBank2 (fromJust result) `elemIndex` banks) + 1)
	hClose output
