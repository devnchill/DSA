// reverses a string
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverse(string s, int start, int end) {
    if (start >= end)
      return s;
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    return reverse(s, start + 1, end - 1);
  }
};

int main() {
  Solution s;
  // olleh
  string h = "hello";
  cout << s.reverse(h, 0, h.size() - 1) << "\n";
  return 0;
}
