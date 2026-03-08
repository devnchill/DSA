-- Split a list into two parts; the length of the first part is given.

split :: [a] -> Int -> [[a]]
split a n =
  let firstPart = map snd (filter (\(i, x) -> i <= n) (zip [1 ..] a))
      secondPart = map snd (filter (\(i, x) -> i > n) (zip [1 ..] a))
   in [firstPart, secondPart]
-- Simpler one
split a n = [take n a, drop n a]
