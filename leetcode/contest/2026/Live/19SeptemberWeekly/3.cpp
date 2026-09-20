// Q3. Maximum Pulse Value After One Subarray Rotation
// Medium
// 5 pt.
// You are given an integer array nums of length n.
//
// Define the pulse value of an integer array arr as the alternating sum
// starting at index 0: pulse(arr) = arr[0] - arr[1] + arr[2] - arr[3] + ....
//
// You may perform at most one operation on nums:
//
// Choose two indices l and r such that 0 <= l < r < n.
// Left-rotate the subarray nums[l..r] by exactly one position. For example, [a,
// b, c, d] becomes [b, c, d, a]. Return the maximum pulse value that can be
// obtained after performing at most one such operation.
//
//
//
// Example 1:
//
// Input: nums = [1,5,2]
//
// Output: 6
//
// Explanation:
//
// The original pulse value is 1 - 5 + 2 = -2.
// Rotate the subarray nums[0..1] from [1, 5] to [5, 1].
// The resulting array is [5, 1, 2] and its pulse value is 5 - 1 + 2 = 6, which
// is the maximum possible. Example 2:
//
// Input: nums = [6,4,3]
//
// Output: 7
//
// Explanation:
//
// The original pulse value is 6 - 4 + 3 = 5.
// Rotate the subarray nums[1..2] from [4, 3] to [3, 4].
// The resulting array is [6, 3, 4] and its pulse value is 6 - 3 + 4 = 7, which
// is the maximum possible. Example 3:
//
// Input: nums = [9,7]
//
// Output: 2
//
// Explanation:
//
// The original pulse value is 9 - 7 = 2, which is already maximum. Thus, no
// rotation is required.
//
//
//
// Constraints:
//
// 1 <= n == nums.length <= 105
// -109 <= nums[i] <= 109
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long max_subarray_sum_even(vector<int> &nums) {
    vector<long long> pmin = {(long long)1e12, (long long)1e12};
    long long ans = 0, pre = 0;
    for (int i = 0; i < nums.size(); i++) {
      pre += nums[i];
      ans = max(ans, pre - pmin[i % 2]);
      if (i % 2)
        ans = max(ans, pre);
      pmin[i % 2] = min(pmin[i % 2], pre);
    }
    return ans;
    // curr_sub - prev_min -> for max
  }
  long long maxValue(vector<int> &nums) {
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i % 2 == 0)
        nums[i] *= (-1);
    }
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    long long fsum = -1 * sum;
    // fsum => max_sub
    // fsum - (-max_sum) + max_sub
    // fsum + 2*max_sub
    long long max_sub = max_subarray_sum_even(nums);
    return max(fsum, 2 * max_sub + fsum);
  }
};
