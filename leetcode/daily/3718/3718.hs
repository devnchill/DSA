import qualified Data.Set as S

missingMultiple :: [Int] -> Int -> Int
missingMultiple nums k =
  head [x | x <- map (* k) [1 ..], S.notMember x s]
  where
    s = S.fromList nums
