minInsertions :: String -> Int
minInsertions s = f s 0 0
  where
    f :: String -> Int -> Int -> Int
    f [] open res = res + 2 * open
    f ('(' : xs) open res =
      f xs (open + 1) res
    f (')' : ')' : xs) open res
      | open > 0 = f xs (open - 1) res
      | otherwise = f xs open (res + 1)
    f (')' : xs) open res
      | open > 0 = f xs (open - 1) (res + 1)
      | otherwise = f xs open (res + 2)
    f (_ : xs) open res =
      f xs open res
