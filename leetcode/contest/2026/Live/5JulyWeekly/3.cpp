#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPossible(string s, string t) {
    int n = s.size(), m = t.size();
    vector<int> pref(n), suf(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
      while (j < m && t[j] != s[i])
        j++;
      if (j == m) {
        pref[i] = m;
      } else {
        pref[i] = j;
        j++;
      }
    }
    if (pref[n - 1] != m)
      return true;
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
      while (j >= 0 && t[j] != s[i])
        j--;
      if (j < 0) {
        suf[i] = -1;
      } else {
        suf[i] = j;
        j--;
      }
    }
    for (int i = 0; i < n; i++) {
      int left = (i == 0) ? -1 : pref[i - 1];
      int right = (i == n - 1) ? m : suf[i + 1];

      if (left != m && right != -1 && left + 1 < right)
        return true;
    }

    return false;
  }
};
