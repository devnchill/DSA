minDistance :: String -> String -> Int
minDistance s1 s2 = f s1 s2 i j
  where
    i = length s1 - 1
    j = length s2 - 1
    f :: String -> String -> Int -> Int -> Int
    f s1 s2 i j
      | i == 0 = j + 1
      | j == 0 = i + 1
      | s1 !! i == s2 !! j = f s1 s2 (i - 1) (j - 1)
      | otherwise =
          1
            + minimum
              [ f s1 s2 i (j - 1),
                f s1 s2 (i - 1) (j - 1),
                f s1 s2 (i - 1) j
              ]
