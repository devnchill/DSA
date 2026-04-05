import qualified Data.Map as Map

-- METHOD 1
judgeCircle :: String -> Bool
judgeCircle path =
  let counts = Map.fromListWith (+) [(c, 1) | c <- path]
      u = Map.findWithDefault 0 'U' counts
      d = Map.findWithDefault 0 'D' counts
      l = Map.findWithDefault 0 'L' counts
      r = Map.findWithDefault 0 'R' counts
   in u == d && l == r

-- METHOD 2
move :: (Int, Int) -> Char -> (Int, Int)
move (x, y) c
  | c == 'L' = (x - 1, y)
  | c == 'R' = (x + 1, y)
  | c == 'U' = (x, y + 1)
  | c == 'D' = (x, y - 1)
  | otherwise = (x, y)

judgeCircle' :: String -> Bool
judgeCircle' = (== (0, 0)) . foldl move (0, 0)
