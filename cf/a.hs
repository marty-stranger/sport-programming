import Data.Graph
import Data.Maybe (fromJust)
import Control.Applicative ((<$>))
import Control.Monad (replicateM)
import Data.ByteString (getLine, getContents)
import Data.ByteString.Char8 (readInt, words, lines)
import Prelude hiding (getLine, words, lines)
import Data.Array.ST (STUArray, newArray, getBounds, readArray, writeArray)

readInts = map (fst . fromJust . readInt) . words <$> getLine

solve n edges queries = "ok"


main = do
	[n] <- readInts
	edges <- map (\[a, b] -> (a, b)) <$> replicateM (n - 1) readInts
	[m] <- readInts
	queries <- replicateM m readInts
	putStrLn $ unlines $ map show $ solve n edges queries

