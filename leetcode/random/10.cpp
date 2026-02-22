// 10. Regular Expression Matching
// Hard
// Topics
// premium lock icon
// Companies
// Given an input string s and a pattern p, implement regular expression
// matching with support for '.' and '*' where:
//
// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
//
//
//
// Example 1:
//
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:
//
// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore,
// by repeating 'a' once, it becomes "aa". Example 3:
//
// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
//
//
// Constraints:
//
// 1 <= s.length <= 20
// 1 <= p.length <= 20
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a
// previous valid character to match.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool match(string &s, string &p, int i, int j) {
    if (j == p.size())
      return i == s.size();

    bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

    if (j + 1 < p.size() && p[j + 1] == '*') {
      return match(s, p, i, j + 2) || (first_match && match(s, p, i + 1, j));
    } else {
      return first_match && match(s, p, i + 1, j + 1);
    }
  }

public:
  bool isMatch(string s, string p) { return match(s, p, 0, 0); }
};
