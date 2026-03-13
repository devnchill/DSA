module P34 where

import P33 (coprime)

-- Calculate Euler's totient function phi(m).

totient :: Int -> Int
totient a = length [x | x <- [1 .. a], coprime x a]

totient' :: Int -> Int
totient' a = sum $ map (fromEnum . (`coprime` a)) [1 .. a]

totient'' :: Int -> Int
totient'' a = length $ filter (`coprime` a) [1 .. a]
