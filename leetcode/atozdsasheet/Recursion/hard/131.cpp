/*
131. Palindrome Partitioning
Medium
Topics
premium lock iconCompanies

Given a string s, partition s such that every
of the partition is a

. Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]

Constraints:

    1 <= s.length <= 16
    s contains only lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> currPartition;
    string currCombination;
    backtrack(res, currPartition, s, 0);
    return res;
  }

private:
  void backtrack(vector<vector<string>> &res, vector<string> &curr, string &s,
                 int index) {
    if (index >= s.size()) {
      res.push_back(curr);
      return;
    }
    for (int i = index; i < s.size(); i++) {
      if (isPalindrome(index, i, s)) {
        string substr = s.substr(index, i - index + 1);
        curr.push_back(substr);
        backtrack(res, curr, s, i + 1);
        curr.pop_back();
      }
    }
  }

  bool isPalindrome(int start, int end, string &s) {
    if (s.size() <= 1)
      return true;
    while (start < end) {
      if (s[start] != s[end])
        return false;
      start++;
      end--;
    }
    return true;
  }
};
