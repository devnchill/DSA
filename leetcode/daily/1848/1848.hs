getMinDistance :: [Int] -> Int -> Int -> Int
getMinDistance nums target start =
  minimum [abs (i - start) | (i, x) <- zip [0 ..] nums, x == target]
