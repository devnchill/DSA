// 647. Palindromic Substrings
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, return the number of palindromic substrings in it.
//
// A string is a palindrome when it reads the same backward as forward.
//
// A substring is a contiguous sequence of characters within the string.
//
//
//
// Example 1:
//
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:
//
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//
//
// Constraints:
//
// 1 <= s.length <= 1000
// s consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// Bruteforce
class Solution {
private:
  bool is_palindrome(string &s) {
    int first = 0, last = s.size() - 1;
    while (first < last) {
      if (s[first] != s[last])
        return false;
      first++;
      last--;
    }
    return true;
  }

public:
  int countSubstrings(string s) {
    int res = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      string sub;
      for (int j = i; j < n; j++) {
        sub.push_back(s[j]);
        if (is_palindrome(sub))
          res++;
      }
    }
    return res;
  }
};

// Approach 2
class Solution2 {
public:
  int count = 0;
  void expand(string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      count++;
      left--;
      right++;
    }
  }

  int countSubstrings(string s) {
    for (int i = 0; i < s.size(); i++) {
      // odd length
      expand(s, i, i);
      // even length
      expand(s, i, i + 1);
    }
    return count;
  }
};
