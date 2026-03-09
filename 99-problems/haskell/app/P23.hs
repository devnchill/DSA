-- Extract a given number of randomly selected elements from a list.
module P23 where

import System.Random

rand_select :: [a] -> Int -> [a]
