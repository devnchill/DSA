countCommas :: Int -> Int
countCommas n
  | n < 1000 = 0
  | otherwise = n - 1000 + 1
