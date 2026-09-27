// Parentheses
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string s that consists of lower case English letters and
// brackets.
//
// Reverse the strings in each pair of matching parentheses, starting from the
// innermost one.
//
// Your result should not contain any brackets.
//
//
//
// Example 1:
//
// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:
//
// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is
// reversed. Example 3:
//
// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally,
// the whole string.
//
//
// Constraints:
//
// 1 <= s.length <= 2000
// s only contains lower case English characters and parentheses.
// It is guaranteed that all parentheses are balanced.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  pair<int, string> rec(int i, string &s) {
    string res;
    while (i < s.size() && s[i] != ')') {
      if (isalpha(s[i])) {
        res.push_back(s[i]);
      } else {
        auto [j, curr] = rec(i + 1, s);
        res += curr;
        i = j;
      }
      i++;
    }
    if (i < s.size()) {
      reverse(res.begin(), res.end());
    }
    return {i, res};
  }

public:
  string reverseParentheses(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        auto [j, curr] = rec(i + 1, s);
        i = j;
        res += curr;
      } else if (s[i] != ')') {
        res.push_back(s[i]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.reverseParentheses("(u(love)i)") << "\n";
}
