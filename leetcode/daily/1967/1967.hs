import Data.List (isInfixOf)

numOfStrings :: [String] -> String -> Int
numOfStrings p w = length $ filter (`isInfixOf` w) p
