// Find last occurrence of element in array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int find_last_occurence(string &s, char c, int i) {
    if (i < 0)
      return -1;
    if (s[i] == c)
      return i;
    return (find_last_occurence(s, c, i - 1));
  }
};

int main() {
  Solution s;
  string st = "hello";
  char c = 'l';
  cout << s.find_last_occurence(st, c, st.size());
  return 0;
}
