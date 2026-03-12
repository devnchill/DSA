-- Determine the greatest common divisor of two positive integer numbers.

myGcd :: Int -> Int -> Int
myGcd a b
  | a == 0 = b
  | otherwise = myGcd b (a `mod` b)
