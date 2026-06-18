angleClock :: Int -> Int -> Double
angleClock hr min = min res $ 360 - res
  where
    res = abs (min * 6 - ((hr `mod` 12) * 30 + min * 1 / 2.0))
