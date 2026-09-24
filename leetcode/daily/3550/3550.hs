smallestIndex :: [Int] -> Int
smallestIndex arr = undefined

sumOfDigits :: Int -> Int
sumOfDigits n = f n 0
  where
    f :: Int -> Int -> Int
    f 0 acc = acc
    f n acc = f (n `mod` 10) (acc + n `mod` 10)
