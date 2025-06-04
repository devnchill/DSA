#include <bits/stdc++.h>
#include <cctype>
using namespace std;
class Solution {
  bool isAlphaNum(char ch) {
    if ((ch >= '0' && ch <= '9') ||
        (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
      return true;
    }
    return false;
  }

public:
  bool ispalindrome(string s) {
    int start = 0;
    int length = s.length();
    int end = length - 1;
    for (size_t i = 0; i < length / 2; i++) {
      if (!isAlphaNum(s[start])) {
        start++;
        continue;
      }
      if (!isAlphaNum(s[end])) {
        end++;
        continue;
      }
      if (tolower(s[start]) == tolower(s[end])) {
        start++;
        end--;
        continue;
      }
      return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string a = "MOM";
  string b = "DAD";
  string c = "SISTER";
  cout << s.ispalindrome(a) << endl;
  cout << s.ispalindrome(b) << endl;
  cout << s.ispalindrome(c) << endl;
  return 0;
}
