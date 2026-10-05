// Given a balanced parentheses string s, return the score of the string.
//
// The score of a balanced parentheses string is based on the following rule:
//
// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
//
//
// Example 1:
//
// Input: s = "()"
// Output: 1
// Example 2:
//
// Input: s = "(())"
// Output: 2
// Example 3:
//
// Input: s = "()()"
// Output: 2
//
//
// Constraints:
//
// 2 <= s.length <= 50
// s consists of only '(' and ')'.
// s is a balanced parentheses string.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int scoreOfParentheses(string s) { return F(s, 0, s.length()); }

private:
  int F(const string &s, int i, int j) {
    int ans = 0, bal = 0;
    for (int k = i; k < j; ++k) {
      bal += (s[k] == '(' ? 1 : -1);
      if (bal == 0) {
        if (k - i == 1) {
          ans++;
        } else {
          ans += 2 * F(s, i + 1, k);
        }
        i = k + 1;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  cout << s.scoreOfParentheses("(())");
}
