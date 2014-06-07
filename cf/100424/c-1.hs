import Data.ByteString.Char8 (getLine, readInteger, words)
import Data.Maybe (fromJust)
import Control.Monad (replicateM_)
import Prelude hiding (getLine, words)

readInt' = fst . fromJust . readInteger

main = do
  t <- readLn

  replicateM_ t $ do
    n <- readInt' `fmap` getLine
    as <- (map readInt' . words) `fmap` getLine
 
    let
      solution = zipWith (\a i -> a * n - i) as [0..]

    putStrLn . unwords . map show $ solution
