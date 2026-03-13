-- A list of prime numbers in a given range.

module P39 where 

primeR :: Int -> Int -> [Int]
primeR a b = [x|x<-[a..b],isPrime x] 
 where 
   isPrime :: Int->Bool 
   isPrime n = n > 1 && all (\k-> n `mod` k /= 0 )[2..n]
