// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
      N = -N;
      x = 1 / x;
    }
    if (N == 0)
      return 1;
    double res = myPow(x, N / 2);
    return N % 2 == 0 ? res * res : res * res * x;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  cout << s.myPow(2, 2);
  return 0;
}
