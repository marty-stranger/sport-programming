import Control.Applicative
import Control.Monad
import Data.Array
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C
import Data.Maybe

toInt = fst . fromJust . C.readInt

main = do
	n <- toInt <$> B.getLine
	[as, bs] <- replicateM 2 $ map toInt . B.split 32 <$> B.getLine
	putStrLn $ unwords $ map show $ elems $ array (1, n) $ zip as bs
	
