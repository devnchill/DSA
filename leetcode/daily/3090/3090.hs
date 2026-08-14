import qualified Data.Map as M

maximumLengthSubstring :: String -> Int
maximumLengthSubstring str =
  f 0 0 M.empty 0
  where
    f :: Int -> Int -> M.Map Char Int -> Int -> Int
    f left right freq ans
      | right == length str = ans
      | otherwise =
          let c = str !! right
              freq1 = M.insertWith (+) c 1 freq
              (left', freq2) = shrink left freq1 c
              ans' = max ans (right - left' + 1)
           in f left' (right + 1) freq2 ans'

    shrink :: Int -> M.Map Char Int -> Char -> (Int, M.Map Char Int)
    shrink left freq c
      | M.findWithDefault 0 c freq <= 2 = (left, freq)
      | otherwise =
          let x = str !! left
              freq' = M.adjust pred x freq
           in shrink (left + 1) freq' c
