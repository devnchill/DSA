import Data.Array

isMatch :: String -> String -> Bool
isMatch s p = dp ! (n, m)
  where
    n = length s
    m = length p
    sa = listArray (1, n) s
    pa = listArray (1, m) p
    dp :: Array (Int, Int) Bool
    dp =
      array
        ((0, 0), (n, m))
        [((i, j), match i j) | i <- [0 .. n], j <- [0 .. m]]

    match :: Int -> Int -> Bool
    match 0 0 = True
    match i 0 =
      False
    match 0 j =
      c j
    match i j
      | sa ! i == pa ! j || pa ! j == '?' =
          dp ! (i - 1, j - 1)
      | pa ! j == '*' =
          dp ! (i - 1, j) || dp ! (i, j - 1)
      | otherwise =
          False

    c :: Int -> Bool
    c 0 = True
    c j =
      pa ! j == '*' && c (j - 1)
