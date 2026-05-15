findMin :: [Int] -> Int
findMin a = func a 0 (length a - 1)
  where
    func :: [Int] -> Int -> Int -> Int
    func a low high
      | low >= high = a !! low
      | a !! mid > a !! high = func a (mid + 1) high
      | otherwise = func a low mid
      where
        mid = low + (high - low) `div` 2
