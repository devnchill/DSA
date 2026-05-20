import qualified Data.Map.Strict as M

findThePrefixCommonArray :: [Int] -> [Int] -> [Int]
findThePrefixCommonArray a b = reverse res
  where
    (_, _, res) =
      foldl step (M.empty, 0, []) (zip a b)

    step (freq, common, ans) (x, y) =
      let freq1 = M.insertWith (+) x 1 freq
          common1 =
            if M.findWithDefault 0 x freq1 == 2
              then common + 1
              else common

          freq2 = M.insertWith (+) y 1 freq1
          common2 =
            if x /= y && M.findWithDefault 0 y freq2 == 2
              then common1 + 1
              else common1
       in (freq2, common2, common2 : ans)
