--  Run-length encoding of a list (direct solution).

data EncodeDirect a = Single a | Multiple Int a

encodeDirect :: (Eq a) => [a] -> [EncodeDirect a]
encodeDirect [] = []
encodeDirect (x : xs) =
  let (chunk, rest) = span (== x) xs
      count = 1 + length chunk
   in ( if count == 1
          then Single x
          else Multiple count x
      )
        : encodeDirect rest
