// Remove duplicates from string s
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string remove_duplicates(string &s, string &res, int i, map<char, int> &m) {
    if (i == s.size())
      return res;

    if (!m[s[i]]) {
      res.push_back(s[i]);
      m[s[i]]++;
    }

    return remove_duplicates(s, res, i + 1, m);
  }
};
;

int main() {
  Solution s;
  string st = "hellohhlkjasdkkskk";
  string res = "";
  map<char, int> m;
  cout << s.remove_duplicates(st, res, 0, m) << "\n";
  return 0;
}
