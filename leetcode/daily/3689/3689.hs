maxTotalValue :: [Int] -> Int -> Int
maxTotalValue xs k = k * (maximum xs - minimum xs)
