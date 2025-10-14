#include <iostream>
using namespace std;
class Solution {
private:
  int count_digits(int n) {
    int count = 0;
    while (n > 0) {
      count++;
      n = n / 10;
    }
    return count;
  }

public:
  bool isArmstrong(int n) {
    int original = n;
    int total_digits = count_digits(n);
    int digit;
    int sum = 0;
    while (n > 0) {
      int product = 1;
      digit = n % 10;
      for (int i = 0; i < total_digits; i++) {
        product *= digit;
      }
      sum += product;
      n = n / 10;
    }
    if (sum == original) {
      return true;
    }
    return false;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  cout << s.isArmstrong(371) << endl;
  cout << s.isArmstrong(1634) << endl;
  cout << s.isArmstrong(21) << endl;
  return 0;
}
