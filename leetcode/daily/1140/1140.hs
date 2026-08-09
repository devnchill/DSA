getStones :: Int -> Int -> [Int] -> Int
getStones i x piles = sum $ take x $ drop i piles

solve :: Bool -> Int -> Int -> [Int] -> Int
solve isAliceTurn m i piles
  | i >= length piles = 0
  | otherwise =
      if isAliceTurn
        then maximum values
        else minimum values
  where
    xs = [1 .. min (2 * m) (length piles - i)]
    values =
      map
        ( \x ->
            let current = getStones i x piles
                future = solve (not isAliceTurn) (max m x) (i + x) piles
             in if isAliceTurn
                  then current + future
                  else future
        )
        xs
