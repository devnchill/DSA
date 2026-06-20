largestAltitude :: [Int] -> Int
largestAltitude xs = maximum $ scanl (+) 0 xs

largestAltitude' :: [Int] -> Int
largestAltitude' = snd . foldl step (0, 0)
  where
    step (alt, best) gain =
      let alt' = alt + gain
       in (alt', max best alt')
