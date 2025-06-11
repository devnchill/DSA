#include <iostream>
using namespace std;
class Solution {
public:
  int SumOfFirstNNumbers(int n) {
    int s = 0;
    if (n == 1) {
      return n;
    }
    return n + SumOfFirstNNumbers(n - 1);
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  cout << s.SumOfFirstNNumbers(5) << endl;
  return 0;
}
