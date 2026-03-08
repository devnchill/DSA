-- Find the number of elements in a list.

myLength :: [a] -> Int
myLength [] = 0
myLength (x : xs) = 1 + myLength xs
-- Inbuilt
myLength a = length a
