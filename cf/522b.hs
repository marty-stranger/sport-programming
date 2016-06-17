import Control.Applicative ((<$>))
import Data.List ((\\))

main = do
	getLine
	sizes <- map ((\[w, h] -> (w, h)) . map read . words) . lines <$> getContents

	let solution =
			map (uncurry solve) sizes
		where
			solve w h =
					(s - w) * (if h == h1 then h2 else h1)
				where
					(ws, hs) = unzip sizes
					s = sum ws
					h1 = maximum hs
					h2 = maximum $ hs \\ [h1]

	putStrLn . unwords $ map show solution
