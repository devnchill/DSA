isSame :: String -> String -> Bool
isSame [a, b, c, d] [w, x, y, z] =
  ((a == w && c == y) || (a == y && c == w))
    && ((b == x && d == z) || (b == z && d == x))
isSame _ _ = False

canBeEqual :: String -> String -> Bool
canBeEqual s1 s2 = s1 == s2 || isSame s1 s2
