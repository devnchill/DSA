#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool validDigit(int n, int x) {
    string temp = to_string(x);
    string t = to_string(n);
    if (t[0] == temp[0])
      return false;
    for (int i = 1; i < t.size(); i++) {
      if (t[i] == temp[0])
        return true;
    }
    return false;
  }
};
