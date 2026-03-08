-- Insert an element at a given position into a list.

insertAt :: a -> [a] -> Int -> [a]
insertAt val arr i
  | i <= 0 || i > length arr = error "index should be less than or equal to length of arr"
  | otherwise = take (i - 1) arr ++ [val] ++ drop (i - 1) arr
