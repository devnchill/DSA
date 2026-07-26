import Data.List (sort)

maximumProduct :: [Int] -> Int
maximumProduct xs =
  let ys = sort xs
      a : b : _ = ys
      c : d : e : _ = reverse ys
   in max (c * d * e) (a * b * c)
