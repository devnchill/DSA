-- Decode a run-length encoded list.
module P12 where

import P11

decodeModified :: [P11.EncodeModified a] -> [a]
decodeModified [] = []
decodeModified (x : xs) =
  case x of
    P11.Single y -> y : decodeModified xs
    P11.Multiple n y -> replicate n y ++ decodeModified xs
