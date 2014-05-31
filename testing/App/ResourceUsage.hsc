{-# LANGUAGE InterruptibleFFI #-}

module App.ResourceUsage where

import Foreign
import Foreign.C

import System.Posix.Process.Internals
import System.Posix.Types

#include <sys/resource.h>
#include <sys/wait.h>

type CRUsage = ()

foreign import ccall interruptible "wait3"
  c_wait3 :: Ptr CInt -> CInt -> Ptr CRUsage -> IO CPid

readWaitStatus wstatp = do
  wstat <- peek wstatp
  decipherWaitStatus wstat

getAnyProcessResourceUsage = do
  allocaBytes (#const sizeof(struct rusage)) $ \p_rusage -> do
    alloca $ \wstatp -> do
      pid <- throwErrnoIfMinus1Retry "getProcessResourceUsage"
        (c_wait3 wstatp (#const WUNTRACED) p_rusage)

      ps <- readWaitStatus wstatp  
      timeUsage <- getTimeUsage p_rusage
      memoryUsage <- getMemoryUsage p_rusage

      return $ (ps, (timeUsage, memoryUsage))

  where
    getTimeUsage p_rusage = do
        let ru_utime = (#ptr struct rusage, ru_utime) p_rusage
        let ru_stime = (#ptr struct rusage, ru_stime) p_rusage
        u_sec  <- (#peek struct timeval,tv_sec)  ru_utime :: IO CTime
        u_usec <- (#peek struct timeval,tv_usec) ru_utime :: IO CSUSeconds
        s_sec  <- (#peek struct timeval,tv_sec)  ru_stime :: IO CTime
        s_usec <- (#peek struct timeval,tv_usec) ru_stime :: IO CSUSeconds
        return $ (realToInteger u_sec * 1000000 + realToInteger u_usec + 
          realToInteger s_sec * 1000000 + realToInteger s_usec)  * 1000000
      where
        realToInteger ct = round (realToFrac ct :: Double)

    getMemoryUsage p_rusage = do
      ru_maxrss <- (#peek struct rusage, ru_maxrss) p_rusage :: IO CLong
      return $ fromIntegral ru_maxrss
