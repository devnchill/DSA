minAddToMakeValid :: String -> Int
minAddToMakeValid s = f s 0 0
  where
    f :: String -> Int -> Int -> Int
    f ('(' : xs) curr res = f xs (curr + 1) res
    f (')' : xs) curr res = if (curr - 1 < 0) then f xs (0) (res + 1) else f xs (curr - 1) res
    f [] curr res = abs curr + res
