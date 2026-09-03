uniformArray :: [Int] -> Bool
uniformArray a
  | null allEven || null allOdd = True
  | otherwise = minimum allEven - minimum allOdd > 0
  where
    l = length a
    allEven = filter even a
    allOdd = filter odd a
