#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, h;
    cin >> n >> m >> h;
    vector<long long> arr;
    vector<long long> add(n, 0);
    vector<int> last_updated(n, 0);
    int time = 0, reset_time = 0;
    for (int i = 0; i < n; i++) {
      int curr;
      cin >> curr;
      arr.push_back(curr);
    }
    for (int i = 0; i < m; i++) {
      int b;
      long long c;
      cin >> b >> c;
      time++;
      b--;
      if (last_updated[b] < reset_time) {
        add[b] = 0;
      }
      add[b] += c;
      last_updated[b] = time;
      if (arr[b] + add[b] > h) {
        reset_time = time;
        add[b] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      if (last_updated[i] < reset_time) {
        add[i] = 0;
      }
      cout << add[i] + arr[i] << "\n";
    }
    cout << "\n";
  }
}
