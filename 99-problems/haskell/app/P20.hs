-- Remove the K'th element from a list.
removeAt :: Int -> [a] -> (a, [a])
removeAt n a = (a !! (n - 1), (take (n - 1) a) ++ drop n a)
