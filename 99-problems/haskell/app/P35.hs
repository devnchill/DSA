import P31 (isPrime)

-- Determine the prime factors of a given positive integer.

module P35 where 

primeFactor :: Int -> [Int]
primeFactor a = [x | x <- [2 .. a], isPrime x, a `mod` x == 0]
