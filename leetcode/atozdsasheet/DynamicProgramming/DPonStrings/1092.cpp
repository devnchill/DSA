// 1092. Shortest Common Supersequence
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings str1 and str2, return the shortest string that has both
// str1 and str2 as subsequences. If there are multiple valid strings, return
// any of them.
//
// A string s is a subsequence of string t if deleting some number of characters
// from t (possibly 0) results in the string s.
//
//
//
// Example 1:
//
// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation:
// str1 = "abac" is a subsequence of "cabac" because we can delete the first
// "c". str2 = "cab" is a subsequence of "cabac" because we can delete the last
// "ac". The answer provided is the shortest such string that satisfies these
// properties. Example 2:
//
// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"
//
//
// Constraints:
//
// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    // Step 1: Find the longest common subsequence using dynamic programming
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (str1[i - 1] == str2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    // Step 2: Construct the shortest common supersequence
    // Start from the bottom right of the dp table
    int i = m, j = n;
    string result = "";

    while (i > 0 && j > 0) {
      if (str1[i - 1] == str2[j - 1]) {
        // If the characters are the same, add it once
        result.push_back(str1[i - 1]);
        i--;
        j--;
      } else if (dp[i - 1][j] > dp[i][j - 1]) {
        // If coming from top has higher value, take character from str1
        result.push_back(str1[i - 1]);
        i--;
      } else {
        // Otherwise, take character from str2
        result.push_back(str2[j - 1]);
        j--;
      }
    }

    // Add remaining characters from str1 (if any)
    while (i > 0) {
      result.push_back(str1[i - 1]);
      i--;
    }

    // Add remaining characters from str2 (if any)
    while (j > 0) {
      result.push_back(str2[j - 1]);
      j--;
    }

    // Reverse the result to get the final supersequence
    reverse(result.begin(), result.end());

    return result;
  }
};
;
