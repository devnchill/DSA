// Find first occurrence of element in array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int find_first_occurence(string &s, char c, int i) {
    if (s[i] == c)
      return i;
    return (find_first_occurence(s, c, i + 1));
  }
};

int main() {
  Solution s;
  string st = "hello";
  char c = 'l';
  cout << s.find_first_occurence(st, c, 0);
  return 0;
}
