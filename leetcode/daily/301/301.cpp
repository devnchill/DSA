#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  set<string> res;
  int min_score = INT_MAX;
  void bfs(const string &s, string &curr, int open, int i, int score) {
    if (i == s.size()) {
      if (open == 0) {
        if (score < min_score) {
          min_score = score;
          res.clear();
          res.insert(curr);
        } else {
          if (score == min_score) {
            min_score = score;
            res.insert(curr);
          }
        }
      }
      return;
    }
    if (s[i] == '(') {
      curr.push_back('(');
      bfs(s, curr, open + 1, i + 1, score);
      curr.pop_back();
      bfs(s, curr, open, i + 1, score + 1);
    } else if (s[i] == ')') {
      if (open <= 0) {
        bfs(s, curr, open, i + 1, score + 1);
      } else {
        curr.push_back(')');
        bfs(s, curr, open - 1, i + 1, score);
        curr.pop_back();
        bfs(s, curr, open, i + 1, score + 1);
      }
    } else {
      curr.push_back(s[i]);
      bfs(s, curr, open, i + 1, score);
      curr.pop_back();
    }
  }

public:
  vector<string> removeInvalidParentheses(string s) {
    string curr = "";
    bfs(s, curr, 0, 0, 0);
    return vector<string>(res.begin(), res.end());
  }
};
