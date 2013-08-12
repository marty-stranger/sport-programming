import Control.Monad
import Control.Monad.ST
import Data.Array.IArray
import Data.Array.ST
import Data.Bits
import qualified Data.ByteString.Char8 as B
import Data.Maybe

-- TODO
-- http://codeforces.ru/contest/165/submission/2510862
-- watashi has shorter solution but my attempt to simplify like he does leads to TLE !?

solve xs = map (compatibles !) xs
	where
		n = 22
		m = 2^n - 1
		--  runSTUArray prevents copying
		-- attempt to STArray Int (Maybe Int) leads to huge memory usage
		compatibles = runSTUArray $ do
			a <- newArray (0, m) $ (-1 :: Int)
			forM_ xs $ \x -> writeArray a (complement x .&. m) $ x
			forM_ (reverse [0..m]) $ \x -> do
				v <- readArray a x
				if v == -1
					then do
						nexts <- mapM (readArray a) $ map (setBit x) $
							filter (not . testBit x) [0..n-1]
						let vs = filter (/= -1) nexts
						if not $ null vs
							then writeArray a x $ head vs
							else return ()
					else return ()
			return a

main = do
	_ <- getLine
	xs <- (map (fst . fromJust . B.readInt) . B.words) `fmap` B.getLine
	putStrLn $ unwords $ map show $ solve xs
