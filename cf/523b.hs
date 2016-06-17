import Control.Applicative ((<$>))
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C
import Data.Maybe (fromJust)

getInts = map (fst . fromJust . C.readInt) . C.words <$> B.getLine

main = do
	(t, c) <- (\[_, t, c] -> (read t, read c :: Float)) . words <$> getLine
	a <- getInts
	B.getLine
	is <- getInts

	let 
		output = map (uncurry output') $ select $ zip real approx
			where
				a' = map fromIntegral a
				t' = fromIntegral t

				output' real approx = (real, approx, abs (approx - real) / real)

				real = map (/ t') $ zipWith (-) sums $ replicate t 0 ++ sums
					where
						sums = scanl1 (+) a'

				approx = tail $ scanl (\m a -> (m + a / t') / c) 0.0 a'

				select vs = select' is vs 1
					where
						select' [] _ _ = []
						select' (i:is) (v:vs) j = 
							if i == j 
								then v : select' is vs (j + 1)
								else select' (i:is) vs (j + 1)


	putStrLn $ unlines $ map (unwords. map show . (\(r, a, e) -> [r, a, e])) output
