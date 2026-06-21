import Data.List (sort)

maxIceCream :: [Int] -> Int -> Int
maxIceCream costs coins = f (sort costs) coins 0
  where
    f [] _ count = count
    f (x : xs) coins count
      | coins < x = count
      | otherwise = f xs (coins - x) count + 1
