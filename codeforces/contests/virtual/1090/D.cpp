#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      long long b1 = 2LL * i - 1;
      long long b2 = 2LL * i + 1;

      cout << b1 * b2 << " ";
    }

    cout << '\n';
  }
}
