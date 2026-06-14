import Data.Char (chr, ord)
import Data.List (foldl')
import qualified Data.Map.Strict as M

type WeightMap = M.Map Char Int

weightMap :: [Int] -> WeightMap
weightMap weights = M.fromList (zip ['a' .. 'z'] weights)

weightString :: String -> WeightMap -> Int
weightString s wm = foldl' (\acc c -> acc + (wm M.! c)) 0 s `mod` 26

mapWordWeights :: [String] -> [Int] -> String
mapWordWeights words weights = let wm = weightMap weights in map (\cw -> chr (ord 'z' - weightString cw wm)) words
