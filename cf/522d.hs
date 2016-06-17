import Control.Applicative ((<$>))
import Data.Array.ST (STUArray)
import Data.Array.MArray (newArray, readArray, writeArray, getBounds)
import Data.Bits ((.&.), (.|.))
import Data.ByteString (getLine, getContents)
import Data.ByteString.Char8 (readInt, words, lines)
import Data.Maybe (fromJust)
import Data.Map qualified (empty, lookup) as Map

import Prelude hiding (getLine, words, lines)

type Fenwick s = STUArray s Int Int
fenwick l = newArray (0, l-1) 0 :: ST s (Fenwick s)

update f (i + 1) d = do
	n <- snd <$> getBounds f
	forM_ (takeWhile (<= n) $ iterate (\i -> i .|. (i + 1)) i) $ \i -> do
		v <- readArray f i
		writeArray f i (v + d)

query f 0 = return 0
query f (i + 1) = do
	sum <$> mapM (readArray f) $ takeWhile (>= 0) $ iterate (\i -> (i .&. (i+1)) - 1) i

readInt' = fst . fromJust . readInt

main = do
	getLine
	as <- map readInt' . words <$> getLine
	queries <- map ((\[a, b] -> (a, b)) . map readInt' . words) . lines <$> getContents

	let result =
		where
			n = length a

			prevs =
					f 1 as Map.empty
				where
					f _ [] m = m
					f i (a:as) m = () : (f (i + 1) as m')
						where
							j = fromMaybe 0 $ Map.lookup a m
							m' = Map.insert a i m
