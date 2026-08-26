{-
 Method 1
 Maybe we first extract all substring with exact k set bits
 then another list with substring of min len among those
 then finally sort this list to get smallest lexicographically string
-}

shortestBeautifulSubstring :: String -> Int -> String
shortestBeautifulSubstring s k = minimum . getMinBeautifulStrs . getBeautifulStr k $ getSubstr s

getSubstr :: String -> [String]
getSubstr s = [(take (end - start + 1) (drop (start) s)) | start <- [0 .. length s], end <- [0 .. length s]]

countOnes :: String -> Int
countOnes = length . filter (== '1')

getBeautifulStr :: Int -> [String] -> [String]
getBeautifulStr k substrs = filter (\x -> countOnes x == k) substrs

getMinBeautifulStrs :: [String] -> [String]
getMinBeautifulStrs strs = let minLen = minimum (map length strs) in filter ((== minLen) . length) strs

{-
 Method 2
 dynamic sliding window
-}
shortestBeautifulSubstring' :: String -> Int -> String
shortestBeautifulSubstring' = undefined
