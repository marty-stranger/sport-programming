import App.Color
import App.Problem
import App.ResourceUsage
import App.Tests

import Control.Monad (forM)
import qualified System.Environment (getArgs)
import Data.String.Utils (strip)
import System.Console.ANSI (Color(..))
import System.Directory (copyFile)
import System.Exit (ExitCode(..))
import System.FilePath.Posix (takeFileName)
import System.Posix.IO (stdInput, stdOutput, handleToFd, closeFd, dup)
import System.Posix.Process (forkProcess, executeFile, ProcessStatus(..))
import System.Posix.Resource (ResourceLimits(..), ResourceLimit(..), Resource(..), setResourceLimit)
import System.Posix.Signals (sigXCPU)
import System.Process (readProcessWithExitCode)
import System.IO (openFile, IOMode(..))

parseArgs = do
  args <- System.Environment.getArgs

  let problemName = args !! 0
  let programName = if length args > 1 then args !! 1 else "a.out"
  let testIndexes = map (read :: String -> Int) $ drop 2 args

  return (problemName, programName, testIndexes)

run programName problem = do
  let limit = ResourceLimit (problemTime problem)
  setResourceLimit ResourceCPUTime (ResourceLimits limit limit)
  -- NOTE ResourceTotalMemory seems to not work on iOS
  -- setResourceLimit ResourceTotalMemory (ResourceLimits ll ll)
  
  inputFd <- openFile "in" ReadMode >>= handleToFd
  closeFd stdInput
  dup inputFd
  
  outputFd <- openFile "out" WriteMode >>= handleToFd
  closeFd stdOutput
  dup outputFd

  executeFile programName False [] Nothing

formatUsages timeUsage memoryUsage = 
    (show $ timeUsage `div` 10000000000) ++ "cs " ++ (show $ memoryUsage `div` 1024) ++ "kb"

main = do
  (problemName, programName, testNums) <- parseArgs

  problem <- readProblemConfig $ problemName ++ "/problem.cfg"
 
  print problem

  tests <- findTests (problemName ++ "/")

  print tests

  usages <- forM tests $ \test -> do
    putStr $ (takeFileName test) ++ " "
    copyFile test "in"
   
    pid <- forkProcess $ run programName problem
    (processStatus, (timeUsage, memoryUsage)) <- getAnyProcessResourceUsage

    case processStatus of
      Exited exitCode ->
        case exitCode of
          ExitSuccess ->
            if memoryUsage >= (problemMemory problem * 1024 * 1024)
            then do
              putColoredStr Blue "mle"
            else do
              (exitCode, stdout, stderr) <- readProcessWithExitCode (problemName ++ "/check") [test, "out", test ++ ".a"] ""
              case exitCode of
                ExitSuccess -> do
                  putColoredStr Green "ok"
                ExitFailure code ->
                  case code of
                    1 -> putColoredStr Red "wa" 
                    127 -> putStr "checker not found"
                    _ -> putColoredStr Red ("failed " ++ show code)
              putStr $ " " ++ (strip stderr)
          ExitFailure code -> do
            putColoredStr Red "re"
      Terminated signal -> do
        case signal of
          sigXCPU -> do
            putColoredStr Blue "tle"

    putColoredStr Blue $ " " ++ (formatUsages timeUsage memoryUsage)

    putStrLn ""
    return (timeUsage, memoryUsage)

  let
    maxTimeUsage = maximum $ map fst $ usages
    maxMemoryUsage = maximum $ map snd $ usages

  putColoredStrLn Blue $ "summary: " ++ (formatUsages maxTimeUsage maxMemoryUsage)
