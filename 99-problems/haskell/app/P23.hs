-- Extract a given number of randomly selected elements from a list.
module P23 (rndSelect) where

import System.Random

rndSelect :: [a] -> Int -> [a]
rndSelect xs n
  | n < 0 = error "n should be greater than 0"
  | otherwise = gen xs n (mkStdGen 100)
  where
    gen _ 0 _ = []
    gen ys k g =
      let (i, g2) = randomR (0, length ys - 1) g
          picked = ys !! i
          rest = take i ys ++ drop (i + 1) ys
       in picked : gen rest (k - 1) g2
