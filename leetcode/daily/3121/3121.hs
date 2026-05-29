import Data.Char (toUpper)

getPosition :: String -> Char -> [Int]
getPosition s c = map (\(_, i) -> i) $ filter (\(x, i) -> x == c) (zip s [0 ..])

getLastLower :: [Int] -> Maybe Int
getLastLower [] = Nothing
getLastLower a = Just $ last a

getFirstUpper :: [Int] -> Maybe Int
getFirstUpper [] = Nothing
getFirstUpper (x : _) = Just x

numberOfSpecialChars :: String -> Int
numberOfSpecialChars s = length $ filter isSpecial ['a' .. 'z']
  where
    isSpecial c = case (getLastLower (getPosition s c), getFirstUpper (getPosition s $ toUpper c)) of
      (Just l, Just u) -> l < u
      _ -> False
