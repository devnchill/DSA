module P40 where

-- Goldbach's conjecture.

import Data.List (find)
import P31

goldBach :: Int -> (Int, Int)
goldBach n
  | n <= 2 || odd n = error "number should be even"
  | otherwise =
      case find (\p -> isPrime p && isPrime (n - p)) [2 .. n `div` 2] of
        Just p -> (p, n - p)
        Nothing -> error "no goldbach pair found"
