#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  int curr = 1;
  while (t--) {
    int len;
    cin >> len;
    vector<int> vec;
    int res = 0;
    int ma = INT_MIN;
    int max_idx = 0, min_idx = 0;
    for (int i = 0; i < len; i++) {
      int curr;
      cin >> curr;
      if (curr > ma) {
        ma = curr;
        max_idx = i;
      }
      vec.push_back(curr);
    }
    swap(vec[max_idx], vec[0]);
    vector<int> pref(len);
    res += vec[0];
    pref.push_back(vec[0]);
    for (int i = 1; i < vec.size(); i++) {
      pref.push_back(max(vec[i], pref.back()));
      res += pref.back();
    }
    cout << res << "\n";
  }
}
