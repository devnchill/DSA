-- Determine the greatest common divisor of two positive integer numbers.
module P32 where

myGcd :: Int -> Int -> Int
myGcd a b
  | b == 0 = a
  | otherwise = myGcd b (a `mod` b)
