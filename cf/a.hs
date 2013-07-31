import Data.Word
solve :: Word32 -> Word32 -> Word32 -> Word32
solve a b 0 = a
solve a b i = seq a (solve b ((3 * a`rem`1000000007 + 2 * b)`rem`1000000007) (i - 1))
main=interact$show.solve 1 0.read
