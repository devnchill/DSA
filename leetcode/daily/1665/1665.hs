import Data.List (sortOn)

minimumEffort :: [[Int]] -> Int
minimumEffort tasks = getMinVal sorted 0 0
  where
    sorted :: [[Int]]
    sorted = sortOn (\[actual, minimum] -> actual - minimum) tasks

    getMinVal :: [[Int]] -> Int -> Int -> Int
    getMinVal [] res _ = res
    getMinVal ([actual, minimum] : xs) res curr
      | minimum > curr =
          let diff = minimum - curr
           in getMinVal xs (res + diff) (curr + diff - actual)
      | otherwise =
          getMinVal xs res (curr - actual)
