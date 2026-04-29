// 583. Delete Operation for Two Strings
// Medium
// Topics
// premium lock icon
// Companies
// Given two strings word1 and word2, return the minimum number of steps
// required to make word1 and word2 the same.
//
// In one step, you can delete exactly one character in either string.
//
//
//
// Example 1:
//
// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make
// "eat" to "ea". Example 2:
//
// Input: word1 = "leetcode", word2 = "etco"
// Output: 4
//
//
// Constraints:
//
// 1 <= word1.length, word2.length <= 500
// word1 and word2 consist of only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int func(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 || j < 0)
      return max(i, j) + 1;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s1[i] == s2[j])
      return func(s1, s2, i - 1, j - 1, dp);
    else
      return 1 + min(func(s1, s2, i - 1, j, dp), func(s1, s2, i, j - 1, dp));
  }

public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
    return func(word1, word2, word1.size() - 1, word2.size() - 1, dp);
  }
};
