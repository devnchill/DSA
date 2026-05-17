import qualified Data.Set as Set

canReach :: [Int] -> Int -> Bool
canReach arr start = dfs Set.empty start
  where
    n = length arr
    dfs visited i
      | i < 0 || i >= n = False
      | Set.member i visited = False
      | arr !! i == 0 = True
      | otherwise =
          dfs visited' (i + jump)
            || dfs visited' (i - jump)
      where
        jump = arr !! i
        visited' = Set.insert i visited
