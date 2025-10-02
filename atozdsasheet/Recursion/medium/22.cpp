
/*
* Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

Constraints:

    1 <= n <= 8
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string current;
    backtrack(res, current, 0, 0, n);
    return res;
  }

private:
  void backtrack(vector<string> &res, string &current, int left, int right,
                 int n) {
    if (current.size() == 2 * n) {
      res.push_back(current);
      return;
    }
    if (left < n) {
      current.push_back('(');
      backtrack(res, current, left + 1, right, n);
      current.pop_back(); // backtrack
    }
    if (right < left) {
      current.push_back(')');
      backtrack(res, current, left, right + 1, n);
      current.pop_back(); // backtrack
    }
  }
};

int main() {
  Solution s;
  vector<string> res = s.generateParenthesis(3);
  for (auto it : res) {
    cout << it << endl;
  }
  return 0;
}
