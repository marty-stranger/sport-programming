{- tle -}
{-# OPTIONS_GHC -O2 #-}

import Data.Array (Array, listArray, (!))
import Data.Array.Base (unsafeRead, unsafeWrite)
import Data.Array.MArray (newArray, newArray_, readArray, writeArray)
import Data.Array.ST (STUArray)
import Data.Bits (shift)
import Data.List (foldl, foldl1', transpose)
import Control.Applicative ((<$>))
import Control.Monad (forM_, mapM, replicateM)
import Control.Monad.ST (ST, runST)

import Debug.Trace (trace)

a +. b = (a + b) `rem` (10^9 + 7)
infixl 6 +.

sum' = foldl1' (+.)

foldM' :: (Monad m) => (a -> b -> m a) -> a -> [b] -> m a
foldM' _ z [] = return z
foldM' f z (x:xs) = do
  z' <- f z x
  z' `seq` foldM' f z' xs

decode 1 0 = 2
decode 1 1 = 3
decode 2 0 = 1
decode 2 1 = 3
decode 3 0 = 1
decode 3 1 = 2

decodeLine :: Int -> (Int, Int) -> [Int]
decodeLine 1 (c, mask) = [c]
decodeLine n (c, mask) = c : (decodeLine (n-1) (c', (mask `div` 2)))
  where
    b = mask `rem` 2
    c' = decode c b

matches :: String -> [Int] -> Bool
matches l1 l2 = and $ zipWith (\c i -> c == '.' || c == ("BWG" !! (i-1))) l1 l2

main = do
  [n, m] <- map read . words <$> getLine
  as <- transpose <$> replicateM n getLine

  let
    gen :: Int -> Int -> [(Int, Int)]
    gen color mask =
        concat [gen' 1 c0 (c0, 0) (color, mask) [] | c0 <- [1..3], c0 /= color]
      where
         gen' i c0 (c1, mask1) (c2, mask2) rs
           | i == n = (c0, mask1) : rs
           | otherwise =
             foldl f rs [c | c <- [1..3], c /= c1, c /= c2']
          where
            mask2' = mask2 `div` 2
            c2' = decode c2 $ mask2 `rem` 2
         
            f rs c = gen' (i + 1) c0 (c, mask1') (c2', mask2') rs
              where
                mask1' = mask1 + ((encode c1 c) `shift` (i - 1))
                  where
                    encode 1 2 = 0
                    encode 1 3 = 1
                    encode 2 1 = 0
                    encode 2 3 = 1
                    encode 3 1 = 0
                    encode 3 2 = 1

    k = 2^(n-1) 

    bounds = ((1, 0), (3, k-1))

    profiles :: [(Int, Int)]
    profiles = [(c, m) | c <- [1..3], m <- [0..k-1]] 

    transitions :: Array (Int, Int) [(Int, Int)]
    transitionsList = [gen c m | (c, m) <- profiles]
    transitions = listArray bounds [gen c m | (c, m) <- profiles]

    solution = trace ("s = " ++ (show $ maximum $ map length transitionsList)) $ runST $ do
      [cs1, cs2] <- replicateM 2 (newArray_ bounds :: ST s (STUArray s (Int, Int) Int))

      forM_ profiles $ \p ->
        if matches (head as) (decodeLine n p)
          then writeArray cs1 p 1
          else writeArray cs1 p 0
      
      forM_ (zip (tail as) $ cycle [0, 1]) $ \(l, i) -> trace (show i) $ do
        let [cs1', cs2'] = take 2 $ drop i $ cycle [cs1, cs2]

        forM_ profiles $ \p -> do
          c <-
              if True -- matches l $ decodeLine n p
                then sum' <$> mapM (readArray cs1') (transitions ! p)
                -- then sum' <$> mapM (\(c, i) -> 3*c + iunsafeRead cs1') (transitions ! p)
                else return 0
   
          writeArray cs2' p c

      let cs = [cs2, cs1] !! ((length as) `rem` 2)

      sum' <$> mapM (readArray cs) profiles

  print solution
