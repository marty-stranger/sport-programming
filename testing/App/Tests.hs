module App.Tests where

import System.FilePath.Find

findTests filepath = find always (fileName ~~? "??") filepath
