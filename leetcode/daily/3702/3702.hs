import Data.Bits (Bits (xor))

longestSubsequence :: [Int] -> Int
longestSubsequence nums =
  let (xr, hasNonZero) =
        foldl
          ( \(xr, hasNonZero) x ->
              ( xr `xor` x,
                hasNonZero || x /= 0
              )
          )
          (0, False)
          nums
   in if xr /= 0
        then length nums
        else
          if hasNonZero
            then length nums - 1
            else 0
