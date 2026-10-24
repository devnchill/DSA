import Data.List (sort)

targetIndices :: [Int] -> Int -> [Int]
targetIndices nums target = map fst . filter (\(i, x) -> x == target) $ zip [0 ..] $ sort nums
