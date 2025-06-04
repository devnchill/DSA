#include <iostream>
using namespace std;
class Solution {
public:
  int Factorial(int n) {
    if (n == 1) {
      return n;
    }
    return n * Factorial(n - 1);
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  cout << s.Factorial(5) << endl;
  return 0;
}
