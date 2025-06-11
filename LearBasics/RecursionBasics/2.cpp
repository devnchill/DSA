#include <iostream>
using namespace std;
class Solution {
public:
  void PrintUptoN(int n, int i = 1) {
    if (i > n) {
      return;
    }
    cout << i << endl;
    i++;
    PrintUptoN(n, i);
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  s.PrintUptoN(10);
  return 0;
}
