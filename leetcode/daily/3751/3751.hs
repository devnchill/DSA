totalWaviness :: Int -> Int -> Int
totalWaviness s e = sum $ map waviness [s .. e]

waviness :: Int -> Int
waviness n = f $ show n
  where
    f (a : b : c : rest)
      | (b > a && b > c) || (b < a && b < c) = 1 + f (b : c : rest)
      | otherwise = f (b : c : rest)
    f _ = 0
