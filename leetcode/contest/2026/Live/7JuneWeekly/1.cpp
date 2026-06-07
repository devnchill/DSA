#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int sumOfGoodIntegers(int n, int k) {
    int sum = 0;
    for (int x = max(1, n - k); x <= n + k; x++) {
      if ((n & x) == 0) {
        cout << "x is: " << x << "\n";
        sum += x;
      }
    }
    return sum;
  }
};

int main() {
  Solution s;
  cout << s.sumOfGoodIntegers(2, 3) << "\n";
}
