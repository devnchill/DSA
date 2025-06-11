#include <iostream>
using namespace std;
class Solution {
public:
  int fib(int n) {
    if (n <= 1) {
      return n;
    }
    return fib(n - 1) + fib(n - 2);
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  cout << s.fib(0) << endl;
  cout << s.fib(1) << endl;
  cout << s.fib(2) << endl;
  cout << s.fib(3) << endl;
  cout << s.fib(4) << endl;
  cout << s.fib(5) << endl;
  cout << s.fib(6) << endl;
  cout << s.fib(7) << endl;
  return 0;
}
