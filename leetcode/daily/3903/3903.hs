import Data.List (findIndex)

firstStableIndex :: [Int] -> Int -> Int
firstStableIndex nums k =
  case findIndex id conditions of
    Just i -> i
    Nothing -> -1
  where
    prefixMax = scanl1 max nums
    suffixMin = scanr1 min nums
    conditions = zipWith (\mx mn -> mx - mn <= k) prefixMax suffixMin
