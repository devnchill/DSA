import Data.Bits (xor)

modVal :: Int
modVal = 1000000007

applyQuery :: [Int] -> [Int] -> [Int]
applyQuery nums [l, r, k, v] =
  [ if i >= l && i <= r && (i - l) `mod` k == 0
      then (x * v) `mod` modVal
      else x
  | (i, x) <- zip [0 ..] nums
  ]
applyQuery nums _ = nums

xorAfterQueries :: [Int] -> [[Int]] -> Int
xorAfterQueries nums queries =
  foldl xor 0 (foldl applyQuery nums queries)
