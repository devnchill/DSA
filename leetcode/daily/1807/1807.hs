import qualified Data.Map as M

evaluate :: String -> [[String]] -> String
evaluate s knowledge =
  let m = foldl (\m (k : v : _) -> M.insert k v m) M.empty knowledge
   in f s
  where
    f [] = ""
    f ('(' : xs) =
      let (key, _ : rest) = span (/= ')') xs
       in M.findWithDefault "?" key m ++ f (tail rest)
    f (x : xs) = x : f xs
