#include <bits/stdc++.h>
using namespace std;

// WIP Incorrect atm
// anyways constraints are big af making bruteforce impossible to work
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<int> robot(n + 1, 0);
    vector<int> pike(n + 1);
    for (int i = 0; i < n; i++) {
      long long curr;
      cin >> curr;
      robot[curr] = 1;
    }
    for (int i = 0; i < m; i++) {
      long long curr;
      cin >> curr;
      pike[curr] = 1;
    }
    string inst;
    cin >> inst;
    for (char ch : inst) {
      if (ch == 'L') {
        for (int i = 1; i < n; i++) {
          robot[i] = 0;
          robot[i - 1] = 1;
        }
      } else {
        for (int i = 1; i < n; i++) {
          robot[i] = 0;
          robot[i + 1] = 1;
        }
      }
    }
  }
}
