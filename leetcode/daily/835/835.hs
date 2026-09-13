import qualified Data.Set as Set

getCoords :: [[Int]] -> [(Int, Int)]
getCoords img =
  [(i, j) | (i, row) <- zip [0 ..] img, (j, x) <- zip [0 ..] row, x == 1]

getEqualSetCoords :: (Ord a) => [a] -> [a] -> Int
getEqualSetCoords a1 a2 =
  let s = Set.fromList a2
   in length [x | x <- a1, x `Set.member` s]

largestOverlap :: [[Int]] -> [[Int]] -> Int
largestOverlap img1 img2 =
  let n = length img1
      s1 = getCoords img1
      s2 = getCoords img2
   in maximum
        [ getEqualSetCoords
            [(x + dx, y + dy) | (x, y) <- s1]
            s2
        | dx <- [-n + 1 .. n - 1],
          dy <- [-n + 1 .. n - 1]
        ]
