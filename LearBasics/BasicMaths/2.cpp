#include <cstdlib>
#include <iostream>
#include <string>
class Solution {
public:
  std::string reverseNumber(int n) {
    std::cout << "value of n before abs is " << n << "\n";
    n = abs(n);
    std::cout << "value of n after abs is " << n << "\n";
    int last_digit;
    int reversed_number = 0;
    while (n > 0) {
      last_digit = n % 10;
      reversed_number = reversed_number * 10 + last_digit;
      n = n / 10;
    }
    return ("value of reverseNumber is " + std::to_string(reversed_number) +
            "\n");
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << "Value of reversed number is " << s.reverseNumber(23)
            << std::endl;
  std::cout << "Value of reversed number is " << s.reverseNumber(-23)
            << std::endl;
  std::cout << "Value of reversed number is " << s.reverseNumber(-93)
            << std::endl;
  std::cout << "Value of reversed number is " << s.reverseNumber(0023)
            << std::endl;
  std::cout << "Value of reversed number is " << s.reverseNumber(03)
            << std::endl;
  return 0;
}
