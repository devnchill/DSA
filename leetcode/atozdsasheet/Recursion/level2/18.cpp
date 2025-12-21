// Move all X to end of string
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string move_x_to_end(string &s) {
    for (char &c : s) {
      c = toupper(c);
    }
  }
};
