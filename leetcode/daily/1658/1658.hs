minOperations :: [Int] -> Int -> Int
minOperations arr x
  | target < 0 = -1
  | best == -1 = -1
  | otherwise = n - best
  where
    n = length arr
    target = sum arr - x

    best = f 0 0 0 (-1)

    f :: Int -> Int -> Int -> Int -> Int
    f left right curr best
      | right == n = best
      | otherwise =
          let curr' = curr + arr !! right
              (left', curr'') = shrink left curr'
              best' =
                if curr'' == target
                  then max best (right - left' + 1)
                  else best
           in f left' (right + 1) curr'' best'

    shrink :: Int -> Int -> (Int, Int)
    shrink left curr
      | curr > target = shrink (left + 1) (curr - arr !! left)
      | otherwise = (left, curr)
