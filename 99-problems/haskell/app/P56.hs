module P56 where

import Btree

symmetric :: Tree Char -> Bool
symmetric (Empty) = True
symmetric (Branch _ l r) = mirror l r

mirror :: Tree Char -> Tree Char -> Bool
mirror Empty Empty = True
mirror (Branch _ l1 r1) (Branch _ l2 r2) = mirror l1 r2 && mirror r1 l2
mirror _ _ = False
