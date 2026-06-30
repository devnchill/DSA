isValidSubarr :: [Int] -> Bool
isValidSubarr = all (> 0)

numberOfSubstrings :: String -> Int
numberOfSubstrings s = go 0 0 [0, 0, 0] 0
  where
    n = length s
    idx c = fromEnum c - fromEnum 'a'
    inc i xs =
      take i xs ++ [xs !! i + 1] ++ drop (i + 1) xs
    dec i xs =
      take i xs ++ [xs !! i - 1] ++ drop (i + 1) xs
    go :: Int -> Int -> [Int] -> Int -> Int
    go left right freq total
      | right == n = total
      | otherwise =
          let freq' = inc (idx (s !! right)) freq
           in shrink left right freq' total

    shrink :: Int -> Int -> [Int] -> Int -> Int
    shrink left right freq total
      | isValidSubarr freq =
          let total' = total + (n - right)
              freq' = dec (idx (s !! left)) freq
           in shrink (left + 1) right freq' total'
      | otherwise =
          go left (right + 1) freq total
