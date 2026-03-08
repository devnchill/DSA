-- Reverse a list.

myReverse :: [a] -> [a]
myReverse [] = []
myReverse [a] = [a]
myReverse (x : xs) = myReverse (xs) ++ [x]
-- inbuilt
myReverse a = reverse a
