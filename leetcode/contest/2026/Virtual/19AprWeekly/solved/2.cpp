#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstStableIndex(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> max_on_left(n, INT_MIN);
    vector<int> min_on_right(n, INT_MAX);
    for (int i = 0; i < n; i++) {
      if (i == 0)
        max_on_left[i] = nums[i];
      else
        max_on_left[i] = max(nums[i], max_on_left[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1)
        min_on_right[i] = nums[i];
      else
        min_on_right[i] = min(nums[i], min_on_right[i + 1]);
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
      int val = max_on_left[i] - min_on_right[i];
      if (val <= k) {
        res = min(res, i);
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};
