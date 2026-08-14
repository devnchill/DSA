// Description
// Editorial
// Editorial
// Solutions
// Solutions
// Submissions
// Submissions
//
//
// Code
//
//
// Testcase
// Testcase
// Test Result
// 3090. Maximum Length Substring With Two Occurrences
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, return the maximum length of a substring such that it
// contains at most two occurrences of each character.
//
//
// Example 1:
//
// Input: s = "bcbbbcba"
//
// Output: 4
//
// Explanation:
//
// The following substring has a length of 4 and contains at most two
// occurrences of each character: "bcbbbcba". Example 2:
//
// Input: s = "aaaa"
//
// Output: 2
//
// Explanation:
//
// The following substring has a length of 2 and contains at most two
// occurrences of each character: "aaaa".
//
//
// Constraints:
//
// 2 <= s.length <= 100
// s consists only of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumLengthSubstring(string s) {
    int res = 0;
    unordered_map<char, int> m;
    for (int right = 0, left = 0; right < s.size(); right++) {
      m[s[right]]++;
      while (m[s[right]] > 2) {
        m[s[left]]--;
        left++;
      }
      res = max(res, right - left + 1);
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.maximumLengthSubstring("aadaad");
}
