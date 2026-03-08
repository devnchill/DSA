-- Flatten a nested list structure.
data NestedList a = Leaf a | Branch [NestedList a] deriving (Show)

myFlatten :: NestedList a -> [a]
myFlatten (Leaf a) = [a]
myFlatten (Branch a) = concatMap myFlatten a
