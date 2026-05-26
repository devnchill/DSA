import Data.Char (isLower, toLower)
import qualified Data.Set as Set

numberOfSpecialChars :: String -> Int
numberOfSpecialChars word =
  Set.size (Set.intersection lower upper)
  where
    lower = Set.fromList [c | c <- word, isLower c]
    upper = Set.fromList [toLower c | c <- word, not (isLower c)]
