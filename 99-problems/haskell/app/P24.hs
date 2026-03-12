module P24 where

import System.Random

diff_select :: Int -> Int -> IO [Int]
diff_select n m = do
  gen <- newStdGen
  return $ take n $ randomRs (1, m) gen
