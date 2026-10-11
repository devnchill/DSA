#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int len;
    cin >> len;
    vector<int> arr;
    for (int i = 0; i < len; i++) {
      int curr;
      cin >> curr;
      arr.push_back(curr);
    }
    sort(arr.begin(), arr.end());
    int curr = 1, best = 1;
    for (int i = 1; i < len; i++) {
      if (arr[i] == arr[i - 1]) {
        continue;
      };
      if (arr[i] == arr[i - 1] + 1) {
        curr++;
      } else {
        curr = 1;
      }
      best = max(best, curr);
    }
    cout << best << "\n";
  }
}
