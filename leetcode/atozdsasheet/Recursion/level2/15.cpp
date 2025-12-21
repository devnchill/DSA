// count occurences
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int count_occurence(string s, char c, int i) {
    if (i < 0)
      return 0;
    return s[i] == c ? 1 + count_occurence(s, c, i - 1)
                     : count_occurence(s, c, i - 1);
  }
};

int main() {
  Solution s;
  cout << s.count_occurence("hellol", 'l', 5);
  return 0;
}
