import Data.Array

numDistinct :: String -> String -> Int
numDistinct s1 s2 = dp ! (n, m)
  where
    n = length s1
    m = length s2

    dp :: Array (Int, Int) Int
    dp =
      array
        ((0, 0), (n, m))
        [((i, j), solve i j) | i <- [0 .. n], j <- [0 .. m]]

    solve :: Int -> Int -> Int
    solve _ 0 = 1
    solve 0 _ = 0
    solve i j
      | s1 !! (i - 1) == s2 !! (j - 1) =
          dp ! (i - 1, j - 1) + dp ! (i - 1, j)
      | otherwise =
          dp ! (i - 1, j)
