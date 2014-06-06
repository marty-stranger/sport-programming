import Data.List (sort)

data Mat22 = Mat22 Integer Integer Integer Integer

(Mat22 a11 a12 a21 a22) *. (Mat22 b11 b12 b21 b22) =
  Mat22 (a11 * b11 + a12 * b21) (a11 * b12 + a12 * b22)
    (a21 * b11 + a22 * b21) (a21 * b12 + a22 * b22)

m `pow` p
  | p == 1 = m
  | even p = let m' = pow m $ p `div` 2 in m' *. m'
  | odd p = m *. (pow m (p - 1))

fibs n = (f, f') where (Mat22 _ f _ f') = pow (Mat22 0 1 1 1) n

main = do
  k <- readLn
  n <- readLn
  as <- (map read . words) `fmap` getLine

  let
    solution
      | k < n = sort as !! k
      | otherwise = maximum $ map calc $ zip as $ tail as
      where
        (f, f') = fibs m where m = k - (n-1)
        calc (a, b) = a' * f + b' * f' where [a', b'] = sort [a, b]

  print $ solution `rem` (10^9 + 7)
