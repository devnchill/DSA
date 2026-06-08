-- METHOD 1
pivotArray :: [Int] -> Int -> [Int]
pivotArray a p = low ++ equal ++ high
  where
    low = filter (\x -> x < p) a
    equal = filter (\x -> x == p) a
    high = filter (\x -> x > p) a

-- METHOD 2
pivotArray' :: [Int] -> Int -> [Int]
pivotArray' a p =
  filter (< p) a ++ filter (== p) a ++ filter (> p) a

-- METHOD 3
pivotArray'' :: [Int] -> Int -> [Int]
pivotArray'' a p = low ++ equal ++ high
  where
    (low, equal, high) = foldr step ([], [], []) a
    step x (l, e, h)
      | x < p = (x : l, e, h)
      | x == p = (l, x : e, h)
      | otherwise = (l, e, x : h)
