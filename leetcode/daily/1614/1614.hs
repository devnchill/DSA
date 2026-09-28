maxDepth :: String -> Int
maxDepth s = f s 0 0
  where
    f :: String -> Int -> Int -> Int
    f [] curr res = res
    f ('(' : rest) curr res =
      let curr' = curr + 1
          res' = max curr' res
       in f rest curr' res'
    f (')' : rest) curr res =
      f rest (curr - 1) res
    f (_ : rest) curr res =
      f rest curr res
