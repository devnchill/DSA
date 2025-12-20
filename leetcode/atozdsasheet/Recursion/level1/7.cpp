// fibonacci
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int get_nth_fibonacci(int n) {
    if (n <= 2)
      return 1;
    return get_nth_fibonacci(n - 1) + get_nth_fibonacci(n - 2);
  }
};
int main() {
  Solution s;
  // 0,1,1,2,3,5,8
  cout << s.get_nth_fibonacci(6);
  return 0;
}
