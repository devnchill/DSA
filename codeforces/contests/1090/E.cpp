#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int res = INT_MIN;
    int len;
    cin >> len;
    vector<int> v;
    for (int i = 0; i < len; i++) {
      int curr;
      cin >> curr;
      v.push_back(curr);
    }
    for (int &val : v) {
      for (int &val2 : v) {
        res = max(res, val ^ val2);
      }
    }
    cout << res << "\n";
  }
}
