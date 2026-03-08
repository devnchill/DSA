 -- Drop every N'th element from a list.
 dropEvery :: [a] -> Int -> [a]
 dropEvery a n = map snd (filter (\(i, x) -> i `mod` n /= 0) (zip [1 ..] a))
