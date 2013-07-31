{-# LANGUAGE UnicodeSyntax #-}

import Control.Applicative
import Data.Array
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C
import Data.Monoid
import Data.Maybe
import Text.Printf

data Max = Max { maxValue :: Int } deriving (Ord, Eq)
data Min = Min { minValue :: Int } deriving (Ord, Eq)

instance Monoid Min where
	mempty = Min maxBound
	mappend = min

instance Monoid Max where
	mempty = Max minBound
	mappend = max

build list = tree 
	where
		n = length list
		tree = listArray (1, 2*n - 1) $ map value [1..n-1] ++ list
		value i = tree ! (2*i) <> tree ! (2*i + 1)

query tree l r = query' (l + n - 1) (r + n - 1)
	where
		n = snd (bounds tree) `div` 2 + 1

		query' l r
			| l > r = mempty
			| odd l = (tree ! l) <> query' (l + 1) r
			| even r = query' l (r - 1) <> (tree ! r)
			| otherwise = query' (l `div` 2) (r `div` 2)

getInts = map (fst . fromJust . C.readInt) . C.words <$> B.getLine

main = do
	[n, k] ← getInts
	as ← getInts

	let maxTree = build $ map Max as
	let minTree = build $ map Min as

	let diff i j = maxValue (query maxTree i j) - minValue (query minTree i j)

	let maxBooksCount i j
		| i == n + 1 = 1
		| otherwise = max (j' - i + 1) (maxBooksCount (i + 1) j')
			where
				j' = last $ takeWhile (\j'' → diff i j'' <= k) [(max i j)..n]

	let m = maxBooksCount 1 1

	let is = [(i, j) | i ← [1..n], let j = i + m - 1, j <= n, diff i j <= k]

	printf "%d %d\n" m (length is)
	sequence $ map (uncurry $ printf "%d %d\n") is