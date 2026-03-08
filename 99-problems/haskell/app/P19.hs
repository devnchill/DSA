-- Rotate a list N places to the left.

rotate :: [a] -> Int -> [a]
rotate a n = (drop n a) ++ take n a
