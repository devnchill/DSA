module Btree where

data Tree a = Empty | Branch a (Tree a) (Tree a)
  deriving (Show, Eq)

leaf :: Int -> Tree Int
leaf x = Branch x Empty Empty
