import Data.Char (digitToInt)

digitSum :: Int -> Int
digitSum = sum . map digitToInt . show

minElement :: [Int] -> Int
minElement = minimum . map digitSum
