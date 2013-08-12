import Control.Applicative
import Data.Maybe
import qualified Data.ByteString.Char8 as B

readWords =  map (fst . fromJust . B.readInt) . B.words <$> B.getLine

solve n m c as bs =
		zipWith (+.) as sums
	where
		a +. b = (a + b) `mod` c
		a -. b = (a - b) `mod` c

		starts = scanl1 (+.) bs
		sums = zipWith (-.) (starts ++ replicate (n-m) (last starts)) (replicate (n-m+1) 0 ++ starts)

main = do
		[n, m, c] <- readWords
		as <- readWords
		bs <- readWords
		putStrLn $ unwords $ map show $ solve n m c as bs
