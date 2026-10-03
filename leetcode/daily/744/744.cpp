// 744. Find Smallest Letter Greater Than Target
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of characters letters that is sorted in non-decreasing
// order, and a character target. There are at least two different characters in
// letters.
//
// Return the smallest character in letters that is lexicographically greater
// than target. If such a character does not exist, return the first character
// in letters.
//
//
//
// Example 1:
//
// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Explanation: The smallest character that is lexicographically greater than
// 'a' in letters is 'c'. Example 2:
//
// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Explanation: The smallest character that is lexicographically greater than
// 'c' in letters is 'f'. Example 3:
//
// Input: letters = ["x","x","y","y"], target = "z"
// Output: "x"
// Explanation: There are no characters in letters that is lexicographically
// greater than 'z' so we return letters[0].
//
//
// Constraints:
//
// 2 <= letters.length <= 104
// letters[i] is a lowercase English letter.
// letters is sorted in non-decreasing order.
// letters contains at least two different characters.
// target is a lowercase English letter.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int low = 0, high = letters.size() - 1;
    int mid = -1;
    int prev_mid = -1;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (letters[mid] == target) {
        while (letters[mid] == target)
          mid += 1;
        if (mid <= letters.size())
          return letters[mid];
        return letters[0];
      }
      if (letters[mid] > target)
        prev_mid = mid, high = mid - 1;
      else
        low = mid + 1;
    }
    if (prev_mid == -1)
      return letters[0];
    return letters[prev_mid];
  }
};
