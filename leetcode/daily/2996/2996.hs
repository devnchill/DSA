import qualified Data.Set as S

missingInteger :: [Int] -> Int
missingInteger lst@(x : y : xs) =
  let s = S.fromList lst
      pfSum = prefixSum lst
   in head $ filter (`S.notMember` s) [pfSum ..]
  where
    prefixSum :: [Int] -> Int
    prefixSum [] = 0
    prefixSum [x] = x
    prefixSum (x : xs) = f x x xs
      where
        f acc prev [] = acc
        f acc prev (y : ys)
          | y == prev + 1 = f (acc + y) y ys
          | otherwise = acc
