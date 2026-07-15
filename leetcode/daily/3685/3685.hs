solution n =
  let a = n * n
      b = n * (n + 1)
   in gcd a b
  where
    gcd a b
      | b == 0 = a
      | otherwise = gcd b (a `mod` b)
