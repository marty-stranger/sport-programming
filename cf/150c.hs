{-# LANGUAGE UnicodeSyntax #-}
{-# OPTIONS_GHC -O3 -optc-O3 -funbox-strict-fields #-}

import Control.Applicative
import Control.Monad
import Data.Array
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C
import Data.Maybe
import Data.Monoid
import Data.Int
import Text.Printf

data Item = Item { itemSum :: !Int64, itemLeftMax :: !Int64, itemRightMax :: !Int64, itemMax :: !Int64 }

instance Monoid Item where
	mempty = Item 0 0 0 0
	mappend (Item as al ar am) (Item bs bl br bm) =
		Item (as + bs) (max al $ as + bl) (max br $ bs + ar) (max (ar + bl) $ max am bm)

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
	[n, m, c] ← getInts
	[xs, ps] ← replicateM 2 $ map fromIntegral <$> getInts
	let as = zipWith (-) (map (*50) $ zipWith (-) (tail xs) xs) (map (* fromIntegral c) ps)
	let tree = build $ map (\a → let b = max 0 a in Item a b b b) as

	ranges ← replicateM m $ (\[l, r] → (l, r - 1)) <$> getInts
	let maxs = map (itemMax . uncurry (query tree)) ranges
	printf "%f" $ (fromIntegral $ sum maxs) / (100 :: Double)
