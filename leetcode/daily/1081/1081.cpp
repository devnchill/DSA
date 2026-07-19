// 1081. Smallest Subsequence of Distinct Characters
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, return the lexicographically smallest subsequence of s that
// contains all the distinct characters of s exactly once.
//
//
//
// Example 1:
//
// Input: s = "bcabc"
// Output: "abc"
// Example 2:
//
// Input: s = "cbacdcbc"
// Output: "acdb"
//
//
// Constraints:
//
// 1 <= s.length <= 1000
// s consists of lowercase English letters.
//
//
// Note: This question is the same as 316:
// https://leetcode.com/problems/remove-duplicate-letters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string smallestSubsequence(string s) {
    stack<char> st;
    vector<bool> visited(26, false);
    unordered_map<char, int> last_occurence;
    for (int i = 0; i < s.size(); i++)
      last_occurence[s[i]] = i;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (visited[ch - 'a'])
        continue;
      if (st.empty()) {
        st.push(ch);
        visited[ch - 'a'] = true;
      } else {
        while (!st.empty() && st.top() > ch && last_occurence[st.top()] > i) {
          visited[st.top() - 'a'] = false;
          st.pop();
        }
        st.push(ch);
        visited[ch - 'a'] = true;
      }
    }
    string res;
    while (!st.empty()) {
      res += st.top(), st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  cout << s.smallestSubsequence("bcabc");
}
