#include <iostream>
using namespace std;
class Solution {
public:
  bool isPrime(int n) {
    int factor = 0;
    for (int i = 1; i <= n; i++) {
      if (n % i == 0)
        factor++;
    }
    if (factor == 2)
      return true;
    return false;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  cout << s.isPrime(2) << endl;
  cout << s.isPrime(4) << endl;
  cout << s.isPrime(5) << endl;
  return 0;
}
