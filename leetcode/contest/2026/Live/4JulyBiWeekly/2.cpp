#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxValidPairSum(vector<int> &nums, int k) {
    int i = 0;
    int n = nums.size();
    int h = nums[i];
    int res = INT_MIN;
    for (int j = k; j < n; j++) {
      h = max(h, nums[j - k]);
      res = max(res, nums[j] + h);
    }
    return res;
  }
};
