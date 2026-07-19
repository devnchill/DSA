import qualified Data.IntSet as S
import qualified Data.Map as M

solution :: String -> String
solution s =
  let lastOcc = M.fromList (zip s [0 ..])
   in f s lastOcc [] S.empty 0
  where
    idx :: Char -> Int
    idx ch = fromEnum ch - fromEnum 'a'

    f :: String -> M.Map Char Int -> String -> S.IntSet -> Int -> String
    f [] _ st _ _ = reverse st
    f (x : xs) lastOcc st vis i
      | S.member (idx x) vis =
          f xs lastOcc st vis (i + 1)
      | otherwise =
          let (st', vis') = popWhile x i st vis lastOcc
           in f
                xs
                lastOcc
                (x : st')
                (S.insert (idx x) vis')
                (i + 1)

    popWhile :: Char -> Int -> String -> S.IntSet -> M.Map Char Int -> (String, S.IntSet)
    popWhile ch i [] vis lastOcc = ([], vis)
    popWhile ch i (top : rest) vis lastOcc
      | top > ch && M.findWithDefault (-1) top lastOcc > i =
          popWhile ch i rest (S.delete (idx top) vis) lastOcc
      | otherwise =
          (top : rest, vis)
