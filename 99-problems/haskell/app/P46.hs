module P46 where

not' :: Bool -> Bool
not' True = False
not' False = True

and', or', xor', nand', impl', equ', nor' :: Bool -> Bool -> Bool
and' True True = True
and' _ _ = False
or' False False = True
or' _ _ = True
nor' a b = not $ or' a b
equ' a b
  | a == b = True
  | otherwise = False
impl' a b = or' (not' a) b
nand' a b = not' $ and' a b
xor' True False = True
xor' False True = True
xor' _ _ = False

infixl 6 `and'`

infixl 4 `or'`

infixl 5 `xor'`

infixl 6 `nand'`

infixl 4 `nor'`

infixr 3 `impl'`

infixl 4 `equ'`

table :: (Bool -> Bool -> Bool) -> IO ()
table f = mapM_ putStrLn [show a ++ " " ++ show b ++ " " ++ show (f a b) | a <- [True, False], b <- [True, False]]
