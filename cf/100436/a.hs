import Control.Applicative

position s = (fromEnum (s !! 0) - fromEnum 'a', fromEnum (s !! 1) - fromEnum '1')

dist (x1, y1) (x2, y2) = max (abs (x2 - x1)) (abs (y2 - y1))

main = do
  [wk, wl, bk] <- map position . words <$> getLine

  let
     underAttack' bk = 
        fst bk == fst wl && (fst wk /= fst bk || snd wk >= max (snd bk) (snd wl) || snd wk <= min (snd bk) (snd wl)) ||
        snd bk == snd wl && (snd wk /= snd bk || fst wk >= max (fst bk) (fst wl) || fst wk <= min (fst bk) (fst wl))

     underAttack = underAttack' bk 

     canMove =
         or $ map (\p -> p /= wk && dist p wk > 1 && (p == wl || not (underAttack' p))) ps
       where
         ps = [(x, y) | x <- [0..7], y <- [0..7], dist (x, y) bk == 1]

  putStrLn $
    if dist wk bk == 1 then
      "Strange"
    else if not underAttack && canMove then
      "Normal"
    else if underAttack && canMove then
      "Check"
    else if not underAttack && not canMove then
      "Stalemate"
    else if underAttack && not canMove then
      "Checkmate"
    else
      undefined
