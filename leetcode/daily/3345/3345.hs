getProdOfNum :: Int -> Int -> Int
getProdOfNum n prod
  | n == 0 = prod
  | otherwise = getProdOfNum (n `div` 10) (prod * (n `mod` 10))

smallestNumber :: Int -> Int -> Int
smallestNumber n t
  | ((getProdOfNum n 1) `mod` t) == 0 = n
  | otherwise = smallestNumber (n + 1) t
