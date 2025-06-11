/*Given the integer day denoting the day number, print on the screen which day
of the week it is. Week starts from Monday and for values greater than 7 or less
than 1, print Invalid.

Ensure only the 1st letter of the answer is capitalised.
*/

#include <iostream>
class Solution {
public:
  void whichWeekDay(int day) {
    if (day < 1 || day > 7) {
      std::cout << "Invalid\n";
      return;
    }
    const std::string dayNames[] = {"Monday",   "Tuesday", "Wednesday",
                                    "Thursday", "Friday",  "Saturday",
                                    "Sunday"};
    std::cout << dayNames[day - 1] << std::endl;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  s.whichWeekDay(8);
  s.whichWeekDay(2);
  s.whichWeekDay(5);
  return 0;
}
