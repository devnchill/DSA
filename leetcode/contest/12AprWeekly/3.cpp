#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxBalancedSubstring(string s) {
    unordered_map<int, int> first;

    int prefix = 0;
    int ans = 0;

    first[0] = -1;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1')
        prefix += 1;
      else
        prefix -= 1;
      if (first.count(prefix)) {
        ans = max(ans, i - first[prefix]);
      }
      if (first.count(prefix - 2)) {
        ans = max(ans, i - first[prefix - 2]);
      }
      if (first.count(prefix + 2)) {
        ans = max(ans, i - first[prefix + 2]);
      }
      if (!first.count(prefix)) {
        first[prefix] = i;
      }
    }

    return ans;
  }
};
