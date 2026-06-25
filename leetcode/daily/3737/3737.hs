import Data.List

-- BruteForce 1 --
countMajoritySubarrays :: [Int] -> Int -> Int
countMajoritySubarrays xs target =
  length $
    filter
      id
      [ f (i, j)
      | i <- [0 .. n - 1],
        j <- [i .. n - 1]
      ]
  where
    n = length xs

    f (i, j) =
      let sub = take (j - i + 1) (drop i xs)
          freq = length (filter (== target) sub)
       in freq > length sub `div` 2

countMajoritySubarrays' :: [Int] -> Int -> Int
countMajoritySubarrays' [] _ = 0
countMajoritySubarrays' ys@(_ : rest) target =
  fun ys 0 0 + countMajoritySubarrays' rest target
  where
    fun [] _ _ = 0
    fun (x : xs) len freq =
      let len' = len + 1
          freq' = if x == target then freq + 1 else freq
          here = if freq' > len' `div` 2 then 1 else 0
       in here + fun xs len' freq'
