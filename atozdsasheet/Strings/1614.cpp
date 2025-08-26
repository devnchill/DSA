/*1614. Maximum Nesting Depth of the Parentheses
Easy
Topics
premium lock iconCompanies
Hint

Given a valid parentheses string s, return the nesting depth of s. The nesting
depth is the maximum number of nested parentheses.

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation:

Digit 3 is inside of 3 nested parentheses in the string.

Example 3:

Input: s = "()(())((()()))"

Output: 3

Constraints:

    1 <= s.length <= 100
    s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
    It is guaranteed that parentheses expression s is a VPS.
*/

#include <iostream>
#include <string>
using std::string;
class Solution {
public:
  int maxDepth(string s) {
    int max_depth = 0;
    int curr_depth = 0;
    for (char ch : s) {
      if (ch == '(')
        curr_depth++;
      if (ch == ')')
        curr_depth--;
      if (curr_depth > max_depth)
        max_depth = curr_depth;
    }
    return max_depth;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.maxDepth("()(())((()()))");
  return 0;
}
