processStr :: String -> String
processStr s = foldl step "" s
  where
    step acc ch =
      case ch of
        '*' -> if null acc then acc else init acc
        '#' -> acc ++ acc
        '%' -> reverse acc
        _ -> acc ++ [ch]
