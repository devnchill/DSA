// You are given an integer array nums of 2 * n integers. You need to partition
// nums into two arrays of length n to minimize the absolute difference of the
// sums of the arrays. To partition nums, put each element of nums into one of
// the two arrays.
//
// Return the minimum possible absolute difference.
//
// Example 1:
//
// example-1
// Input: nums = [3,9,7,3]
// Output: 2
// Explanation: One optimal partition is: [3,9] and [7,3].
// The absolute difference between the sums of the arrays is abs((3 + 9) - (7 +
// 3)) = 2. Example 2:
//
// Input: nums = [-36,36]
// Output: 72
// Explanation: One optimal partition is: [-36] and [36].
// The absolute difference between the sums of the arrays is abs((-36) - (36))
// = 72. Example 3:
//
// example-3
// Input: nums = [2,-1,0,4,-2,-9]
// Output: 0
// Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
// The absolute difference between the sums of the arrays is abs((2 + 4 + -9) -
// (-1 + 0 + -2)) = 0.
//
//
// Constraints:
//
// 1 <= n <= 15
// nums.length == 2 * n
// -107 <= nums[i] <= 107

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumDifference(vector<int> &nums) {
    int n = nums.size() / 2;

    vector<int> left(nums.begin(), nums.begin() + n);
    vector<int> right(nums.begin() + n, nums.end());

    vector<vector<int>> leftSum(n + 1), rightSum(n + 1);
    for (int mask = 0; mask < (1 << n); mask++) {
      int lsum = 0, rsum = 0, bits = 0;

      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          lsum += left[i];
          rsum += right[i];
          bits++;
        }
      }
      leftSum[bits].push_back(lsum);
      rightSum[bits].push_back(rsum);
    }

    for (int i = 0; i <= n; i++) {
      sort(rightSum[i].begin(), rightSum[i].end());
    }

    int total = accumulate(nums.begin(), nums.end(), 0);
    int ans = INT_MAX;

    for (int k = 0; k <= n; k++) {
      for (int l : leftSum[k]) {
        int need = (total / 2) - l;

        auto &vec = rightSum[n - k];
        auto it = lower_bound(vec.begin(), vec.end(), need);

        if (it != vec.end()) {
          int sum = l + *it;
          ans = min(ans, abs(total - 2 * sum));
        }

        if (it != vec.begin()) {
          --it;
          int sum = l + *it;
          ans = min(ans, abs(total - 2 * sum));
        }
      }
    }
    return ans;
  }
};
