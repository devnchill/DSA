data Node
  = Empty
  | Node
      { val :: Int,
        next :: Node
      }

pairSum :: Node -> Int
pairSum ll =
  let oList = goOver ll
      revList = reverse oList
      n = length oList
   in maximum $ take n $ zipWith (+) oList revList
  where
    goOver :: Node -> [Int]
    goOver Empty = []
    goOver (Node v nxt) = v : goOver nxt
