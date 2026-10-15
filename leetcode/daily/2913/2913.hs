import Data.List (inits, nub, tails)

sumCounts :: [Int] -> Int
sumCounts =
  sum
    . map (\sub -> let k = length (nub sub) in k * k)
    . concatMap (tail . inits)
    . tails
