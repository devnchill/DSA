// check palindrome
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool is_palindrome(string s, int start, int end) {
    if (start >= end)
      return true;
    if (s[start] == s[end])
      return is_palindrome(s, start + 1, end - 1);
    return false;
  }
};

int main() {
  Solution s;
  cout << s.is_palindrome("dad", 0, 2) << "\n";
  return 0;
}
