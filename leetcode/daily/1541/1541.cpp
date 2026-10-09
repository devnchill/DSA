// 1541. Minimum Insertions to Balance a Parentheses String
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a parentheses string s containing only the characters '(' and ')'. A
// parentheses string is balanced if:
//
// Any left parenthesis '(' must have a corresponding two consecutive right
// parenthesis '))'. Left parenthesis '(' must go before the corresponding two
// consecutive right parenthesis '))'. In other words, we treat '(' as an
// opening parenthesis and '))' as a closing parenthesis.
//
// For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))"
// and "(()))" are not balanced. You can insert the characters '(' and ')' at
// any position of the string to balance it if needed.
//
// Return the minimum number of insertions needed to make s balanced.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    stack<char> st;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (ch == '(') {
        st.push(ch);
      } else {
        if (i + 1 < s.size() && s[i + 1] == ')') {
          if (!st.empty()) {
            st.pop();
          } else {
            res++;
          }
          i++;
        } else {
          res++;
          if (!st.empty()) {
            st.pop();
          } else
            res++;
        }
      }
    }
    return st.empty() ? res : res + 2 * st.size();
  };
};

int main() {
  Solution s;
  cout << s.minInsertions("))())(");
}
