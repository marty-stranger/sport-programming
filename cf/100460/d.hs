import Control.Arrow ((***))
import Control.Monad (replicateM)
import Data.Sequence (Seq)
import qualified Data.Sequence as Seq
import Data.Set (Set)
import qualified Data.Set as Set
import Data.Vector ((!), Vector)
import qualified Data.Vector as Vector

import Debug.Trace (trace)

readWords = fmap (map read . words) getLine

solve a n m v s t =
    t `elem` reachable
  where
    reachable =
        search (Seq.singleton s) (Set.singleton s) []
      where
        search queue browsed result
          | Seq.null queue = result
          | otherwise = trace ("search: " ++ (show c) ++ " unbrowsed = " ++ (show unbrowsed) ++ " nexts = " ++ (show nexts)) $
            search queue'' browsed' (c : result)
          where
            c@(x0, y0) Seq.:< queue' = Seq.viewl queue

            unbrowsed = concatMap outermost [(x0 + k, y0), (x0 - k, y0), (x0, y0 + k), (x0, y0 - k)]
              where
                outermost c = scan c []
                  where
                    scan c@(x0, y0) found =
                      if inRhomb c && `Set.notMember` browsed
                      | not $ inRhomb c = found
                      where
                        inRhomb (x, y) = abs (x - x0) + abs (y - y0) <= v
                        adjacent = [(x0 + 1, y0), (x0 - 1, y0), (x0, y0 + 1), (x0, y0 - 1)]


            ((+), const), (const, subtract), (subtract, const), (const, (+))]
              where
                outermost (f, g) = trace ("outermose: c' = " ++ (show c')) $ scan c' []
                  where
                    c' = cram $ (f v) *** (g v) $ c
                      where
                        cram (x, y) = (max 0 (min (n - 1) x), max 0 (min (m - 1) y))

                    scan c@(x0, y0) found
                      | not $ good c = found
                      | otherwise = scan below (more ++ found)
                      where
                        good c = inside c && c `Set.notMember` browsed
                          where
                            inside (x, y) = 0 <= x && x < n && 0 <= y && y < m && abs (x - x0) + abs (y - y0) <= v

                        isConst f = (f 5 10 == 5)

                        vect@(vx, vy) = ((f 1 0), (g 1 0))
                        vect'@(vx', vy') = (-vx, -vy)
                        rot45 = (vx' + vy', -vx' + vy')
                        padd (px, py) (vx, vy) = (px + vx, py + vy)

                        move2vec =

                        move1 = (f' 1) *** (g' 1)
                          where (f', g') = (if isConst f then const else opposite f, if isConst g then const else opposite g)
                        move2 = (f' 1) *** (g' 1)
                          where (f', g') = (if isConst f then g else opposite , if isConst g then (+) else opposite g)

                        more = takeWhile good $ iterate move1 c
                        below = move2 c

            browsed' = foldl (flip Set.insert) browsed unbrowsed
            nexts = filter (\(x, y) -> a ! x ! y == 'F') unbrowsed
            queue'' = foldl (Seq.|>) queue' nexts

main = do
  [n, m, v] <- readWords
  [x0, y0, x1, y1] <- readWords
  a <- fmap (Vector.fromList . map Vector.fromList) $ replicateM n getLine
  let r = solve a n m v (x0 - 1, y0 - 1) (x1 - 1, y1 - 1)
  putStrLn $ if r then "Hello, Deimos!" else "Dire victory"
