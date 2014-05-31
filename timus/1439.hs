{- sketch -}
#!/usr/bin/env runhaskell
{-# OPTIONS_GHC -O2 -optc-O2 -funbox-strict-fields #-}
{-# LANGUAGE BangPatterns, MagicHash #-}
import Control.Monad (replicateM)
import qualified Data.Array as Array
import Data.ByteString.Char8 (words, getLine, readInt)
import qualified Data.ByteString.Char8 as ByteString
import Data.Maybe (fromJust)
import qualified Data.Map as Map
import Debug.Trace (trace)
import Prelude hiding (words, getLine)

readWords = fmap (map (fst . fromJust . readInt) . words) getLine

solve n actions =
    solve' (Set.empty) actions []
  where
    shiftedIndex deleted i =
        i + Set.size less + fromEnum pivot
      where
        (_, pivot, less) = Set.splitMember i deleted

    solve' _ [] results = reverse results
    solve' deleted (('D', i):actions) results = trace ("deleted = " ++ (show deleted) ++ " j = " ++ (show j)) $
        solve' deleted' actions results
      where
        j = shiftedIndex deleted i
        deleted' = Set.insert j deleted

    solve' deleted (('L', i):actions) results = trace ("L " ++ " i = " ++ (show i) ++ " deleted = " ++ (show deleted)) $
        solve' deleted actions (j:results)
      where
        j = shiftedIndex deleted i

main = do
  [n, m] <- readWords

  actions <- replicateM m $ fmap ((\[w1, w2] -> (ByteString.head w1, (fst $ fromJust $ readInt w2))) . words) getLine

  kputStr $ unlines $ map show $ solve n actions
