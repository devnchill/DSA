#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  int curr = 1;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {

      cout << curr * curr << " ";
      curr++;
    }
    cout << "\n";
  }
}
