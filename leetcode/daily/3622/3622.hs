import Data.Char (digitToInt)

checkDivisibility :: Int -> Bool
checkDivisibility n = n `mod` (s + p) == 0
  where
    digits = map digitToInt $ show n
    s = sum digits
    p = product digits
