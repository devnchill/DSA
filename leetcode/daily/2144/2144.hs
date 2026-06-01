import Data.List (sort)

minimumCost :: [Int] -> Int
minimumCost = sum . map snd . filter (\(i, _) -> i `mod` 3 /= 2) . zip [0 ..] . reverse . sort
