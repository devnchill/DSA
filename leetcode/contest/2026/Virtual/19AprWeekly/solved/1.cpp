#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstStableIndex(vector<int> &nums, int k) {
    int res = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int mi = INT_MIN;
      int ma = INT_MAX;
      for (int j = 0; j <= i; j++) {
        mi = max(mi, nums[j]);
      }
      for (int k = i; k < nums.size(); k++) {
        ma = min(ma, nums[k]);
      }
      if (mi - ma <= k)
        res = min(res, i);
    }
    return res == INT_MAX ? -1 : res;
  }
};
