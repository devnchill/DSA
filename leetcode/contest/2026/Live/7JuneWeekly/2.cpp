#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<string> res;
  void solve(string &s, int pos, bool prevOne, int cost, int n, int k) {

    if (cost > k)
      return;
    if (pos == n) {
      res.push_back(s);
      return;
    }

    s.push_back('0');
    solve(s, pos + 1, false, cost, n, k);
    s.pop_back();
    if (!prevOne) {
      s.push_back('1');
      solve(s, pos + 1, true, cost + pos, n, k);
      s.pop_back();
    }
  }

public:
  vector<string> generateValidStrings(int n, int k) {
    string s;
    solve(s, 0, false, 0, n, k);
    return res;
  }
};

int main() {
  Solution s;
  auto res = s.generateValidStrings(3, 1);
  for (string &st : res)
    cout << "st is :" << st << "\n";
}
