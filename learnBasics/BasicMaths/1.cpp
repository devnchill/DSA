/*
You are given an integer n. You need to return the number of digits in the
number.
The number will have no leading zeroes, except when the number is 0 itself.
*/

#include <cstdlib>
#include <iostream>
class Solution {
public:
  int countDigit(int n) {
    if (n == 0) {
      return 1;
    }
    int no_of_digits = 0;
    n = abs(n);
    while (n > 0) {
      no_of_digits++;
      n = n / 10;
    }
    return no_of_digits;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.countDigit(22) << std::endl;
  std::cout << s.countDigit(-83999) << std::endl;
  std::cout << s.countDigit(0) << std::endl;
  std::cout << s.countDigit(8002) << std::endl;
  return 0;
}
