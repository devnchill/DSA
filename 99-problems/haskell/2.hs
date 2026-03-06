-- Find the last-but-one (or second-last) element of a list.

myButLast :: [a] -> a
myButLast [] = error "list should have minimum of 2 elements"
myButLast [a] = error "list should have minimum of 2 elements"
myButLast [a, b] = a
myButLast (x : xs) = myButLast xs
-- using inbuilt method
myButLast a = a !! (length a - 2)
