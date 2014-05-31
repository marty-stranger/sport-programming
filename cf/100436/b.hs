{- ok -}
import Control.Applicative ((<$>))
import Control.Monad (replicateM)
import Data.Array (listArray, (!))
import Data.Char (isAlpha, toLower)
import Data.List (elemIndex)
import Data.Maybe (fromMaybe)

import Debug.Trace (trace)

main = do
  [a, b, s] <- replicateM 3 $ map toLower <$> getLine
  k <- readLn
 
  let
    solution = k `elemIndex` suitableFibs
       where
         occurencesIn = length . filter (== s) . words . map (\c -> if isAlpha c then c else ' ')
         c1 = occurencesIn a
         c2 = occurencesIn b

         fibs = (toInteger c1) : (toInteger c2) : [x + y | (x, y) <- zip fibs (tail fibs)]
         suitableFibs = takeWhile (<= k) fibs

  putStrLn $ fromMaybe "Impossible" (show <$> solution)
