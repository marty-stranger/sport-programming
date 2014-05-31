{- sketch -}
#!/usr/bin/env runhaskell
{-# OPTIONS_GHC -O2 -optc-O2 -funbox-strict-fields #-}
{-# LANGUAGE BangPatterns, MagicHash #-}
import Control.Monad (replicateM)
import Data.ByteString.Char8 (words, getLine, readInt)
import qualified Data.ByteString.Char8 as ByteString
import Data.Maybe (fromJust)
import qualified Data.Sequence as Seq
import Debug.Trace (trace)
import Prelude hiding (words, getLine)

readWords = fmap (map (fst . fromJust . readInt) . words) getLine

solve n actions =
    solve' initial actions []
  where

    initial = Seq.fromList $ take n $ [1..]

    solve' _ [] results = reverse results
    solve' rooms (('D', i):actions) results =
        solve' rooms' actions results
      where
        (rooms1, rooms2) = Seq.splitAt i rooms
        rooms' = rooms1 Seq.>< (Seq.drop 1 rooms2)
    solve' rooms (('L', i):actions) results = -- trace ("r = " ++ show result) $
        solve' rooms actions (result:results)
      where
        result = Seq.index rooms i

main = do
  [n, m] <- readWords

  actions <- replicateM m $ fmap ((\[w1, w2] -> (ByteString.head w1, (fst $ fromJust $ readInt w2) - 1)) . words) getLine

  putStr $ unlines $ map show $ solve n actions
