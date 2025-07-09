#include <iostream>
class Solution {
public:
  void studentGrade(int marks) {
    if (marks >= 90) {
      std::cout << "Grade A";
    } else if (marks >= 70) {
      std::cout << "Grade B";
    } else if (marks >= 50) {
      std::cout << "Grade C";
    } else if (marks >= 35) {
      std::cout << "Grade D";
    } else {
      std::cout << "Fail";
    }
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  s.studentGrade(88);
  return 0;
}
