sumOfSquares :: [Int] -> Int
sumOfSquares vec = f vec size 1 0
  where
    size = length vec
    f :: [Int] -> Int -> Int -> Int -> Int
    f [] _ _ res = res
    f (x : xs) size idx res
      | size `mod` idx == 0 = f xs size (idx + 1) $ res + (x * x)
      | otherwise = f xs size (idx + 1) res
