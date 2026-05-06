#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool isPrime(int x) {
    if (x < 2)
      return false;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0)
        return false;
    }
    return true;
  }

public:
  int sumOfPrimesInRange(int n) {
    string temp = to_string(n);
    reverse(temp.begin(), temp.end());
    int rev = stoi(temp);
    int mi = min(n, rev);
    int ma = max(n, rev);
    int res = 0;

    for (int i = mi; i <= ma; i++) {
      if (isPrime(i)) {
        res += i;
      }
    }

    return res;
  }
};
