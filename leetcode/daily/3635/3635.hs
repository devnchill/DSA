earliestFinishTime :: [Int] -> [Int] -> [Int] -> [Int] -> Int
earliestFinishTime ls ld ws wd =
  min (solve ls ld ws wd) (solve ws wd ls ld)
  where
    solve s1 d1 s2 d2 =
      minimum $ zipWith (\s d -> max s finish1 + d) s2 d2
      where
        finish1 = minimum $ zipWith (+) s1 d1
