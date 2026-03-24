-- Bruteforce
getProductMatrix :: [[Int]] -> [[Int]]
getProductMatrix a =
  let prod = product (concat a)
   in map (map (\x -> prod `div` x)) a

-- Using Prefix & Suffix
reshape :: [Int] -> [a] -> [[a]]
reshape [] _ = []
reshape (n : ns) xs =
  let (row, rest) = splitAt n xs
   in row : reshape ns rest

getProductMatrix' :: [[Int]] -> [[Int]]
getProductMatrix' a =
  let flat = concat a
      prefix = init (scanl (*) 1 flat)
      suffix = tail (scanr (*) 1 flat)
      resultFlat = zipWith (*) prefix suffix
   in reshape (map length a) resultFlat
