countDaysTogether :: String -> String -> String -> String -> Int
countDaysTogether aa la ab lb =
  let a_a_d = dayOfYear aa
      a_l_d = dayOfYear la
      b_a_d = dayOfYear ab
      b_l_d = dayOfYear lb
      start = max a_a_d b_a_d
      end = min a_l_d b_l_d
   in if start > end
        then 0
        else end - start + 1

parseDate :: String -> (Int, Int)
parseDate [m1, m2, '-', d1, d2] = (read [m1, m2], read [d1, d2])

dayOfYear :: String -> Int
dayOfYear date = let (month, day) = parseDate date in sum (take (month - 1) days) + day
  where
    days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
