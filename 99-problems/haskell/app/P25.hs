-- Generate a random permutation of the elements of a list.
module P25 where

import Data.List (sortOn)
import System.Random

rnd_permu :: [a] -> IO [a]
rnd_permu a = do
  gen <- newStdGen
  return $ map snd $ sortOn fst $ zip (randoms gen :: [Int]) a
