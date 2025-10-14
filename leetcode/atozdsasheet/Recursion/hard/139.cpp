/*
139. Word Break
Medium
Topics
premium lock iconCompanies

Given a string s and a dictionary of strings wordDict, return true if s can be
segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the
segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen
apple". Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false



Constraints:

    1 <= s.length <= 300
    1 <= wordDict.length <= 1000
    1 <= wordDict[i].length <= 20
    s and wordDict[i] consist of only lowercase English letters.
    All the strings of wordDict are unique.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[n] = true;

    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    for (int i = n - 1; i >= 0; i--) {
      for (auto &word : wordDict) {
        int len = word.size();
        if (i + len <= n && s.substr(i, len) == word) {
          if (dp[i + len]) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[0];
  }
};
