import Control.Monad (foldM)
import Data.List (sort)

-- METHOD 1 --
-- Foldl would end up iterating till the end,can't short circuit
asteroidsDestroyed :: Int -> [Int] -> Bool
asteroidsDestroyed m a = snd $ foldl (\(acc, b) x -> if x > acc then (acc, False) else (acc + x, b)) (m, True) $ sort a

-- METHOD 2 --
asteroidsDestroyed' :: Int -> [Int] -> Bool
asteroidsDestroyed' m xs = f m $ sort xs
  where
    f _ [] = True
    f acc (x : xs)
      | x > acc = False
      | otherwise = f (acc + x) xs

-- METHOD 3 --
asteroidsDestroyed'' :: Int -> [Int] -> Bool
asteroidsDestroyed'' m xs =
  case foldM step m (sort xs) of
    Just _ -> True
    Nothing -> False
  where
    step :: Int -> Int -> Maybe Int
    step acc x
      | x > acc = Nothing
      | otherwise = Just (acc + x)
