sequentialDigits :: Int -> Int -> [Int]
sequentialDigits l h =
  let s = "123456789"
      lsize = length $ show l
      hsize = length $ show h
   in map (\(len, i) -> read $ take len $ drop i s) [(len, i) | len <- [lsize .. hsize], i <- [0 .. 9 - len]]
