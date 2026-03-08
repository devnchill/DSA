 -- Extract a slice from a list.
 slice :: [a] -> Int -> Int -> [a]
 slice a start end = take (end - start + 1) $ drop (start - 1) a
