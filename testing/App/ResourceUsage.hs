{-# LINE 1 "App/ResourceUsage.hsc" #-}
{-# LANGUAGE InterruptibleFFI #-}
{-# LINE 2 "App/ResourceUsage.hsc" #-}

module App.ResourceUsage where

import Foreign
import Foreign.C

import System.Posix.Process.Internals
import System.Posix.Types


{-# LINE 12 "App/ResourceUsage.hsc" #-}

{-# LINE 13 "App/ResourceUsage.hsc" #-}

type CRUsage = ()

foreign import ccall interruptible "wait3"
  c_wait3 :: Ptr CInt -> CInt -> Ptr CRUsage -> IO CPid

readWaitStatus wstatp = do
  wstat <- peek wstatp
  decipherWaitStatus wstat

getAnyProcessResourceUsage = do
  allocaBytes (144) $ \p_rusage -> do
{-# LINE 25 "App/ResourceUsage.hsc" #-}
    alloca $ \wstatp -> do
      pid <- throwErrnoIfMinus1Retry "getProcessResourceUsage"
        (c_wait3 wstatp (2) p_rusage)
{-# LINE 28 "App/ResourceUsage.hsc" #-}

      ps <- readWaitStatus wstatp  
      timeUsage <- getTimeUsage p_rusage
      memoryUsage <- getMemoryUsage p_rusage

      return $ (ps, (timeUsage, memoryUsage))

  where
    getTimeUsage p_rusage = do
        let ru_utime = ((\hsc_ptr -> hsc_ptr `plusPtr` 0)) p_rusage
{-# LINE 38 "App/ResourceUsage.hsc" #-}
        let ru_stime = ((\hsc_ptr -> hsc_ptr `plusPtr` 16)) p_rusage
{-# LINE 39 "App/ResourceUsage.hsc" #-}
        u_sec  <- ((\hsc_ptr -> peekByteOff hsc_ptr 0))  ru_utime :: IO CTime
{-# LINE 40 "App/ResourceUsage.hsc" #-}
        u_usec <- ((\hsc_ptr -> peekByteOff hsc_ptr 8)) ru_utime :: IO CSUSeconds
{-# LINE 41 "App/ResourceUsage.hsc" #-}
        s_sec  <- ((\hsc_ptr -> peekByteOff hsc_ptr 0))  ru_stime :: IO CTime
{-# LINE 42 "App/ResourceUsage.hsc" #-}
        s_usec <- ((\hsc_ptr -> peekByteOff hsc_ptr 8)) ru_stime :: IO CSUSeconds
{-# LINE 43 "App/ResourceUsage.hsc" #-}
        return $ (realToInteger u_sec * 1000000 + realToInteger u_usec + 
          realToInteger s_sec * 1000000 + realToInteger s_usec)  * 1000000
      where
        realToInteger ct = round (realToFrac ct :: Double)

    getMemoryUsage p_rusage = do
      ru_maxrss <- ((\hsc_ptr -> peekByteOff hsc_ptr 32)) p_rusage :: IO CLong
{-# LINE 50 "App/ResourceUsage.hsc" #-}
      return $ fromIntegral ru_maxrss
