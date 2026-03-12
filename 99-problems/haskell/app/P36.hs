-- Determine the prime factors and their multiplicities of a given positive integer.
module P36 where

import P35

primeFactorsMult :: Int -> [(Int, Int)]
primeFactorsMult n =
  map (\xs -> (head xs, length xs)) $ group (primeFactor n)
