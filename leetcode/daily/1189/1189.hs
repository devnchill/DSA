import Data.List (foldl')
import qualified Data.Map.Strict as Map

maxNumberOfBalloons :: String -> Int
maxNumberOfBalloons s =
  minimum [f 'b', f 'a', f 'l' `div` 2, f 'o' `div` 2, f 'n']
  where
    mp = foldl' (\m c -> Map.insertWith (+) c 1 m) Map.empty s
    f c = Map.findWithDefault 0 c mp
