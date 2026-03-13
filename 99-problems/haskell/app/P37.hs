-- Calculate Euler's totient function phi(m) (improved).

module P37 where

import Data.List (group)

phi :: Int -> Int
phi n = foldl (\acc grp -> acc * ((head grp - 1) * head grp ^ (length grp - 1))) 1 (group [x | x <- [2 .. n], gcd x n == 1])
