-- Modified run-length encoding.
module P11 where

import P10

data EncodeModified a = Multiple Int a | Single a
  deriving (Show)

encodeModified :: (Eq a) => [a] -> [EncodeModified a]
encodeModified [] = []
encodeModified a =
  let intialVal = P10.encode a
   in map
        (\(a, b) -> if a == 1 then Single b else Multiple a b)
        intialVal
