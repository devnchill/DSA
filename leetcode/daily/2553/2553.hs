import Data.Char (digitToInt)

separateDigits :: [[Int]] -> [Int]
separateDigits nums = concatMap (map digitToInt . show) nums
