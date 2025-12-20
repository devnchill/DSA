// Count digits in a number

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int count_digits(int n) {
    if (n < 0)
      n = abs(n);
    if (n / 10 == 0) {
      if (n >= 0)
        return 1;
      return 0;
    }
    return 1 + count_digits(n / 10);
  }
};

int main() {
  Solution s;
  cout << s.count_digits(-3522);
  return 0;
}
