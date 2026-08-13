import qualified Data.Map as M

maxSubarrayLength :: [Int] -> Int -> Int
maxSubarrayLength lst k =
  f lst 0 0 M.empty (length lst) 0
  where
    shrink :: [Int] -> Int -> Int -> Int -> M.Map Int Int -> (Int, M.Map Int Int)
    shrink lst k left right freq
      | M.findWithDefault 0 (lst !! right) freq <= k =
          (left, freq)
      | otherwise =
          let x = lst !! left
              freq' = M.insert x (M.findWithDefault 0 x freq - 1) freq
           in shrink lst k (left + 1) right freq'
    f :: [Int] -> Int -> Int -> M.Map Int Int -> Int -> Int -> Int
    f lst left right freq len res
      | right == len =
          res
      | otherwise =
          let x = lst !! right
              freq' =
                M.insert x (M.findWithDefault 0 x freq + 1) freq
              (left', freq'') =
                shrink lst k left right freq'
              res' =
                max res (right - left' + 1)
           in f lst (left') (right + 1) freq'' len res'
