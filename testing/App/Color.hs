module App.Color where

import System.Console.ANSI (Color(..), setSGR, SGR(..), ConsoleLayer(..), ColorIntensity(..))

putColoredStr color s = do
  setSGR [SetColor Foreground Dull color]
  putStr s
  setSGR []

putColoredStrLn color s = do
   putColoredStr color s
   putStrLn ""
