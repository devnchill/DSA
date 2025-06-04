#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(int n) {
    int original = n;
    int last_digit;
    int reversed_number = 0;
    while (n > 0) {
      last_digit = n % 10;
      if (reversed_number > (INT_MAX - last_digit) / 10) {
        return false;
      }
      reversed_number = reversed_number * 10 + last_digit;
      n = n / 10;
    }
    if (original == reversed_number) {
      cout << "true" << endl;
      return true;
    }
    cout << "false" << endl;
    return false;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  cout << s.isPalindrome(22) << endl;
  cout << s.isPalindrome(32) << endl;
  return 0;
}
