import Control.Monad
import Control.Monad.ST
import Data.Array
import Data.Array.Base
import Data.Array.ST

-- import Data.Word
-- import Data.Int as I

f = runST $ do
  let l = 10^6 + 10
  a <- newArray (0, l-1) 0 :: ST s (STUArray s Int Int)

  {-let update i = do-}
        {-v <- readArray a i-}
        {-writeArray a (i `div` 2) (v + 1)-}

  {-forM_ [0..10^6-1] update-}

  let update i
        | i == 0 = return i
        | otherwise = do
          v <- readArray a i
          v' <- readArray a (i + 1)
          if v <= v' then do
            writeArray a (i + 1) (v + 1)
            update (i - 1)
          else return i

  i' <- update (10^6 - 1)

  return i'

main = do
  print $ f

