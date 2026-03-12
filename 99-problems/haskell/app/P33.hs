-- Determine whether two positive integer numbers are coprime.

module P33 where

coprime :: Int -> Int -> Bool
coprime a b = gcd a b == 1
