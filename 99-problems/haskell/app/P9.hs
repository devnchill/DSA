module P9 (pack) where

-- Pack consecutive duplicates of list elements into sublists
pack :: (Eq a) => [a] -> [[a]]
pack [] = []
pack (x : xs) =
  let (ys, zs) = span (== x) xs
   in (x : ys) : pack zs
