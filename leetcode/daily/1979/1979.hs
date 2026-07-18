import Data.List (sort)

solution :: [Int] -> Int
solution [] = error "empty list"
solution xs = gcd (minimum xs) (maximum xs)
  where
    gcd f l
      | l == 0 = f
      | otherwise = gcd l $ f `mod` l
