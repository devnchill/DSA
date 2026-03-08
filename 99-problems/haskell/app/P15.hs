-- Replicate the elements of a list a given number of times.

replic :: (Eq a) => [a] -> Int -> [a]
replic _ 0 = []
replic (x : xs) n = myReplicate x n ++ replic xs n
  where
    myReplicate _ 0 = []
    myReplicate x n = x : myReplicate x (n - 1)
