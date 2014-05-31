import Control.Monad
import Control.Monad.ST (runST)
import Control.Monad.ST
import qualified Data.Vector.Unboxed.Mutable as V
import qualified Data.Vector.Primitive.Mutable as P
import Data.Word

applyM :: Monad m => Int -> (Int -> a -> m a) -> a -> m a
applyM n f v0 = do
    let loop i v
            | i < n    = do
                v' <- f i v
                loop (i+1) v'
            | otherwise = return v
    loop 0 v0

f = runST $ do
  let l = 10^6
  a <- V.new l -- :: ST s (V.MVector s Word64)
  let ll = 10^6 :: Word64
  -- replicateM_ (10^6) $  V.unsafeWrite a 0 3
  -- mapM_ (\_ -> V.unsafeWrite a 0 3) [0..ll-1]
  -- foldM (\i _ -> V.unsafeWrite a 0 3
  applyM (10^6) (\a -> V.unsafeRead (0 :: Int)) (0 :: Int)
  return 5

main = do
  print $ f

