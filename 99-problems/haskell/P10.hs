module P10 where

import P9

-- Run-length encoding of a list.
encode :: (Eq a) => [a] -> [(Int, a)]
encode [] = []
encode a =
  let initial_val = P9.pack a
   in map (\x -> (length x, head x)) initial_val
