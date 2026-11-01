minMoves :: [Int] -> Int
minMoves n = sum $ map (subtract mi) n
  where
    mi = minimum n
