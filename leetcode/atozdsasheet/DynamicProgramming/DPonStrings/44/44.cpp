// 44. Wildcard Matching
// Hard
// Topics
// premium lock icon
// Companies
// Given an input string (s) and a pattern (p), implement wildcard pattern
// matching with support for '?' and '*' where:
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
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
// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:
//
// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not
// match 'b'.
//
//
// Constraints:
//
// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<int>> dp;
  bool check(string &s1, string &s2, int i, int j) {
    if (j < 0 && i < 0) {
      return true;
    }
    if (j < 0)
      return false;

    if (i < 0) {
      while (j >= 0) {
        if (s2[j] != '*')
          return false;
        j--;
      }
      return true;
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s1[i] == s2[j] || s2[j] == '?')
      return dp[i][j] = check(s1, s2, i - 1, j - 1);

    if (s2[j] == '*')
      return dp[i][j] = check(s1, s2, i - 1, j) || check(s1, s2, i, j - 1);
    return dp[i][j] = false;
  }

public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    dp.resize(n, vector<int>(m, -1));
    return check(s, p, n - 1, m - 1);
  }
};

int main() {
  Solution s;
  cout << s.isMatch("aa", "*") << "\n";
}
