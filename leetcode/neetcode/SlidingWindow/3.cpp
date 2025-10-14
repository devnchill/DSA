/*
3. Longest Substring Without Repeating Characters
Medium
Topics
premium lock iconCompanies
Hint

Given a string s, find the length of the longest

without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and
"cab" are also correct answers.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a
substring.

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int len = s.size();
    int left = 0;
    set<char> se;
    int max_len = 0;
    for (int right = 0; right < len; right++) {
      while (se.count(s[right])) {
        se.erase(s[left]);
        left++;
      }
      se.insert(s[right]);
      max_len = max(max_len, right - left + 1);
    }
    return max_len;
  }
};
