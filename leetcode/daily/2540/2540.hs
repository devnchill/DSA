getCommon :: [Int] -> [Int] -> Int
getCommon [] _ = -1
getCommon _ [] = -1
getCommon (x1 : xs1) (x2 : xs2)
  | x1 == x2 = x1
  | x1 > x2 = getCommon (x1 : xs1) xs2
  | otherwise = getCommon (xs1) (x2 : xs2)
