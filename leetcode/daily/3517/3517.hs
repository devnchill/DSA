smallestPalindrome :: String -> String
smallestPalindrome s = left ++ mid ++ reverse left
  where
    freq :: [Int]
    freq = map (\c -> length (filter (== c) s)) ['a' .. 'z']

    left :: String
    left =
      concat $
        zipWith
          (\c f -> replicate (f `div` 2) c)
          ['a' .. 'z']
          freq

    mid :: String
    mid =
      [ c
      | (c, f) <- zip ['a' .. 'z'] freq,
        odd f
      ]
