/*
678. Valid Parenthesis String
Medium
Topics
premium lock icon
Companies
Hint
Given a string s containing only three types of characters: '(', ')' and '*',
return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left
parenthesis '(' or an empty string "".


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  map<string, bool> m;

  bool backtrack(int i, string &s, int open, int len) {
    if (i == len)
      return open == 0;
    string key = to_string(i) + "," + to_string(open);
    if (m.count(key))
      return m[key];
    bool is_valid = false;
    if (s[i] == '(')
      is_valid = backtrack(i + 1, s, open + 1, len);
    else if (s[i] == '*') {
      is_valid = backtrack(i + 1, s, open + 1, len) ||
                 backtrack(i + 1, s, open, len) ||
                 (open > 0 ? backtrack(i + 1, s, open - 1, len) : false);
    } else if (open > 0)
      is_valid = backtrack(i + 1, s, open - 1, len);
    return m[key] = is_valid;
  }

public:
  bool checkValidString(string s) { return backtrack(0, s, 0, s.size()); }
};
;
