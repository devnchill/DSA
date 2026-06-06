-- METHOD 1

res :: [Int] -> [Int] -> [Int]
res a b = zipWith (\x y -> abs (x - y)) a b

leftSum :: [Int] -> [Int]
leftSum = init . scanl (+) 0

righSums :: [Int] -> [Int]
righSums xs = zipWith (\l x -> total - l - x) left xs
  where
    total = sum xs
    left = leftSum xs

leftRightDifferent :: [Int] -> [Int]
leftRightDifferent a = res (leftSum a) (righSums a)

-- METHOD 2

leftRightDifferent' :: [Int] -> [Int]
leftRightDifferent' xs = go 0 total xs
  where
    total = sum xs

    go :: Int -> Int -> [Int] -> [Int]
    go _ _ [] = []
    go left right (x : xs) = let right' = right - x in abs (left - right') : go (left + x) right' xs
