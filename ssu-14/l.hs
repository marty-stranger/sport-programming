{-# LANGUAGE BangPatterns, TupleSections #-}
{-# OPTIONS_GHC -O2 -optc-O2-funbox-strict-fields #-}

import Control.Monad (replicateM)
import Data.ByteString.Char8 (readInt, words, getLine)
import Data.Maybe (fromJust)
import qualified Data.Vector as Vector
import Prelude hiding (getLine, readInt, words)

-- readWords = (map read . words) `fmap` getLine
readWords = (map (fst . fromJust . readInt) . words) `fmap` getLine

data Event = Event { eventAttitude :: Int, eventPersons :: ![Int] }

solve m events =
    if and $ zipWith (==) maxs (map eventAttitude events) then
      Just $ Vector.toList mins
    else
      Nothing
  where
    mins0 = Vector.replicate m (10^9)
    mins = Vector.accum min mins0 $
      concatMap (\(Event a ps) -> map (, a) ps) events

    maxs = map (maximum . map (mins Vector.!) . eventPersons) events

main = do
  [n, m] <- readWords
  events <- replicateM n $ do
    [_, a] <- readWords
    ps <- (map (\x -> x - 1)) `fmap` readWords
    return $ Event a ps

  let r = solve m events

  case r of
    (Just attitudes) -> do
      putStrLn "Good memory"
      putStrLn $ unwords $ map show attitudes
    Nothing ->
      putStrLn "Poor memory"
