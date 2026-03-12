-- Determine whether a given integer number is prime.

module P31 where

isPrime :: Int -> Bool
isPrime n
  | n <= 1 = False
  | otherwise = countDivisors n == 0
  where
    countDivisors x = length [d | d <- [2 .. floor (sqrt (fromIntegral x :: Double))], x `mod` d == 0]

isPrime' :: Int -> Bool
isPrime' n
  | n <= 1 = False
  | otherwise = not (any (\d -> n `mod` d == 0) [2 .. floor (sqrt (fromIntegral n :: Double))])

isPrime'' :: Int -> Bool
isPrime'' n
  | n <= 1 = False
  | n == 2 = True
  | even n = False
  | otherwise = checkDiv 3
  where
    limit = floor (sqrt (fromIntegral n :: Double))
    checkDiv d
      | d > limit = True
      | n `mod` d == 0 = False
      | otherwise = checkDiv (d + 2)
