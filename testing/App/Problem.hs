module App.Problem where

import Data.ConfigFile (readfile, emptyCP, get)
import Data.Either.Utils (forceEither)

data Problem = Problem
  { problemTime :: Integer
  , problemMemory :: Integer
  } deriving (Show)

readProblemConfig path = do
  config <- forceEither `fmap` readfile emptyCP path
  let time = forceEither $ get config "DEFAULT" "time" :: Integer
  let memory = forceEither $ get config "DEFAULT" "memory" :: Integer
  return $ Problem { problemTime = time, problemMemory = memory }
