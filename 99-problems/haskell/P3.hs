-- Find the K'th element of a list.

elementAt :: [a] -> Int -> a
elementAt [] _ = error "list is empty"
elementAt (x : xs) k
  | k == 1 = x
  | k > 1 = elementAt xs (k - 1)
  | otherwise = error "invalid k"
-- Inbuilt Method way
elementAt x k = x !! (k - 1)
