-- A list of even numbers and their Goldbach compositions in a given range.
module P41 where 

import P40

goldBachList :: Int-> Int-> [(Int ,Int)]
goldBachList start end = map (goldBach) [x|x<-[start..end],even x]
