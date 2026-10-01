isValid :: String -> Bool
isValid = f []
  where
    f st [] = null st
    f st (c : cs)
      | c `elem` "([{" = f (c : st) cs
      | otherwise =
          case st of
            x : xs -> matches x c && f xs cs
            [] -> False

    matches '(' ')' = True
    matches '[' ']' = True
    matches '{' '}' = True
    matches _ _ = False
