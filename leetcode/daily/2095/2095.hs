data ListNode
  = Empty
  | ListNode
      { val :: Int,
        next :: ListNode
      }
  deriving (Show)

deleteMiddle :: ListNode -> ListNode
deleteMiddle xs =
  let n = lengthList xs
      mid = n `div` 2
   in removeAt mid xs

lengthList :: ListNode -> Int
lengthList Empty = 0
lengthList (ListNode _ nxt) = 1 + lengthList nxt

removeAt :: Int -> ListNode -> ListNode
removeAt _ Empty = Empty
removeAt 0 (ListNode _ nxt) = nxt
removeAt k (ListNode v nxt) =
  ListNode v (removeAt (k - 1) nxt)
