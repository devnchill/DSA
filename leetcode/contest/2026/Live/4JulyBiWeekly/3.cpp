#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(string s1, string s2) {
    int n = s1.size();
    int res = 0;
    if (n == 1)
      return s1 == s2 ? 0 : s1[0] == '0' ? 1 : -1;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i])
        continue;
      if (s2[i] == '1' && s1[i] == '0') {
        res++;
        s1[i] = '1';
        continue;
      }
      if (s2[i] == '0' && s1[i] == '1') {
        if (i + 1 < n && s1[i + 1] == '1') {
          res++;
          s1[i + 1] = '0';
          s1[i] = '0';
          continue;
        }
        if (i + 1 < n && s1[i + 1] == '0') {
          res += 2;
          s1[i + 1] = '0';
          s1[i] = '0';
          continue;
        }
        if (i - 1 >= 0) {
          res += 2;
          s1[i] = '0';
        }
      }
    }
    return res;
  }
};
