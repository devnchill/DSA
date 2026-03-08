-- Duplicate the elements of a list.

dupli :: (Eq a) => [a] -> [a]
dupli [] = []
dupli (x : xs) =
  let (chunk, rest) = span (== x) (x : xs)
   in replicate ((length chunk) * 2) x ++ dupli rest
