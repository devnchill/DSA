dfs :: Int -> [[Int]] -> [Bool] -> [Bool]
dfs node graph vis =
  let vis' = map (\(i, v) -> if i == node then True else v) (zip [0 ..] vis)
   in foldl (\currentVis neighbor -> if currentVis !! neighbor then currentVis else dfs neighbor graph currentVis) vis' (graph !! node)

remainingMethods :: Int -> Int -> [[Int]] -> [Int]
remainingMethods n k invocations =
  let graph = buildGraph n invocations
      vis = dfs k graph (replicate n False)

      bad = any (\[a, b] -> not (vis !! a) && vis !! b) invocations
   in if bad
        then [0 .. n - 1]
        else [i | i <- [0 .. n - 1], not (vis !! i)]

buildGraph :: Int -> [[Int]] -> [[Int]]
buildGraph n invocations =
  foldl addEdge (replicate n []) invocations
  where
    addEdge graph [a, b] =
      take a graph
        ++ [graph !! a ++ [b]]
        ++ drop (a + 1) graph
