#include <iostream>
using namespace std;
class Solution {
public:
  void PrintNTimes(int n) {
    if (n == 0) {
      return;
    }
    PrintNTimes(n - 1);
    cout << "hi" << n << endl;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  s.PrintNTimes(5);
  return 0;
}
