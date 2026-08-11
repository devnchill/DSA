maxProfit :: Int -> [Int] -> Int
maxProfit k prices = rec prices 0 True 0 k
  where
    rec :: [Int] -> Int -> Bool -> Int -> Int -> Int
    rec prices i canBuy numTransaction k
      | i == length prices || numTransaction == k = 0
      | canBuy = max (-(prices !! i) + rec prices (i + 1) (not canBuy) numTransaction k) (rec prices (i + 1) canBuy numTransaction k)
      | otherwise = max ((prices !! i) + rec prices (i + 1) (not canBuy) (numTransaction + 1) k) (rec prices (i + 1) canBuy numTransaction k)
