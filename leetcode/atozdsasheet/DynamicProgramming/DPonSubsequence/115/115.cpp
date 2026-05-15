// Given two strings s and t, return the number of distinct subsequences of s
// which equals t.
//
// The test cases are generated so that the answer fits on a 32-bit signed
// integer.
//
//
//
// Example 1:
//
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:
//
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
//
//
// Constraints:
//
// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> dp;
  int func(string &s1, string &s2, int i, int j) {
    if (j < 0)
      return 1;
    if (i < 0)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s1[i] == s2[j])
      return dp[i][j] = func(s1, s2, i - 1, j - 1) + func(s1, s2, i - 1, j);
    else
      return dp[i][j] = func(s1, s2, i - 1, j);
  }

public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    dp.resize(n, vector<int>(m, -1));
    return func(s, t, n - 1, m - 1);
  }
};
