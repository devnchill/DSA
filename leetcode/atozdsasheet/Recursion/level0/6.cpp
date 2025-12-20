// Power function pow(a, b) (no loops)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int power(int n, int k) {
    if (k == 0)
      return 1;
    return n * power(n, k - 1);
  }
};

int main() {
  Solution s;
  cout << s.power(3, 2);
  return 0;
}
