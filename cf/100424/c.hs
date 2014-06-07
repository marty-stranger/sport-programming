import Data.ByteString.Char8 (getLine, readInt, words)
import Data.Function (on)
import Data.List (sort, groupBy)
import Data.Maybe (fromJust)
import Data.Tuple (swap)
import Control.Monad (replicateM_)
import Prelude hiding (getLine, words)

readInt' = fst . fromJust . readInt

main = do
  t <- readLn

  replicateM_ t $ do
    n <- readInt' `fmap` getLine
    as <- (map readInt' . words) `fmap` getLine
 
    let
      solution = map snd . sort . map swap . zip [1..] . concat . map (reverse . map snd) . groupBy ((==) `on` fst) . sort $ zip as [1..]

    putStrLn . unwords . map show $ solution
