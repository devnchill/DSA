#include <iostream>
class Solution {
public:
  void printNumber() {
    int num;
    std::cin >> num;
    std::cout << num;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  sol.printNumber();
  return 0;
}
