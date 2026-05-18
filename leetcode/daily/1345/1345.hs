import Data.Foldable (toList)
import qualified Data.IntMap.Strict as IM
import qualified Data.IntSet as IS
import qualified Data.Sequence as Seq

minJumps :: [Int] -> Int
minJumps arr
  | n == 1 = 0
  | otherwise = bfs initialQueue initialVisited mp 0
  where
    n = length arr
    mp :: IM.IntMap [Int]
    mp =
      IM.fromListWith
        (++)
        [(x, [i]) | (i, x) <- zip [0 ..] arr]
    initialQueue = Seq.singleton 0
    initialVisited = IS.singleton 0
    bfs :: Seq.Seq Int -> IS.IntSet -> IM.IntMap [Int] -> Int -> Int
    bfs Seq.Empty _ _ _ = -1
    bfs q visited m steps =
      processLevel (length q) q visited m
      where
        processLevel 0 nq nv nm =
          bfs nq nv nm (steps + 1)
        processLevel sz (i Seq.:<| rest) vis curMap
          | i == n - 1 = steps
          | otherwise =
              processLevel (sz - 1) finalQueue finalVisited nextMap
          where
            sameValue =
              IM.findWithDefault [] (arr !! i) curMap
            neighbors =
              sameValue ++ [i - 1, i + 1]
            valid =
              [ j
              | j <- neighbors,
                j >= 0,
                j < n,
                not (IS.member j vis)
              ]
            finalVisited =
              foldr IS.insert vis valid
            finalQueue =
              rest Seq.>< Seq.fromList valid
            nextMap =
              IM.insert (arr !! i) [] curMap
