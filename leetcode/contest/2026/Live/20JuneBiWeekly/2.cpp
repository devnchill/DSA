#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minLights(vector<int> &lights) {
    int n = lights.size();
    vector<int> diff(n + 1, 0);
    for (int i = 0; i < n; i++) {
      if (lights[i] > 0) {
        int l = max(0, i - lights[i]);
        int r = min(n - 1, i + lights[i]);
        diff[l]++;
        if (r + 1 < n)
          diff[r + 1]--;
      }
    }
    vector<int> illuminate(n, 0);
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += diff[i];
      illuminate[i] = (cur > 0);
    }
    vector<int> dark;
    for (int i = 0; i < n; i++) {
      if (!illuminate[i])
        dark.push_back(i);
    }
    int res = 0;
    for (int i = 0; i < (int)dark.size();) {
      int j = i;
      while (j + 1 < (int)dark.size() && dark[j + 1] == dark[j] + 1) {
        j++;
      }
      int len = j - i + 1;
      res += (len + 2) / 3;
      i = j + 1;
    }
    return res;
  }
};
