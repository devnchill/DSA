maxSumOfSquares :: Int -> Int -> String
maxSumOfSquares num sum
  | num * 9 < sum = ""
  | otherwise = f "" num sum
  where
    f :: String -> Int -> Int -> String
    f st num sum
      | length st < num = let curr = min 9 sum in f (st ++ show curr) num (sum - curr)
      | otherwise = st
