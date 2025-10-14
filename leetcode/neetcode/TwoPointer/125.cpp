
/*125. Valid Palindrome
Attempted
Easy
Topics
premium lock iconCompanies

A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    string temp;
    for (auto it : s) {
      if (isalnum(it) != 0)
        temp.push_back((char)(tolower(it)));
    }
    if (temp.size() == 0)
      return true;
    int len = temp.size();
    for (int i = 0; i <= (len - 1) / 2; i++) {
      if (temp[i] != temp[len - 1 - i])
        return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome("A man, a plan, a canal: Panama");
  return 0;
}
