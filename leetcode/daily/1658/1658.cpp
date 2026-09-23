//
// Code
// Testcase
// Testcase
// Test Result
// 1658. Minimum Operations to Reduce X to Zero
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums and an integer x. In one operation, you
// can either remove the leftmost or the rightmost element from the array nums
// and subtract its value from x. Note that this modifies the array for future
// operations.
//
// Return the minimum number of operations to reduce x to exactly 0 if it is
// possible, otherwise, return -1.
//
//
//
// Example 1:
//
// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to
// reduce x to zero. Example 2:
//
// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
// Example 3:
//
// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and
// the first two elements (5 operations in total) to reduce x to zero.
//
//
// Constraints:
//
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
// 1 <= x <= 109

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    long long sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < x)
      return -1;
    int left = 0, right = 0;
    int n = nums.size();
    long long curr = 0;
    int best = -1;
    while (right < n) {
      curr += nums[right];
      if (curr == sum - x) {
        best = max(best, right - left + 1);
      } else if (curr > sum - x) {
        while (curr > sum - x) {
          curr -= nums[left];
          left++;
        }
        if (curr == sum - x) {
          best = max(best, right - left + 1);
        }
      }
      right++;
    }
    return best == -1 ? -1 : n - best;
  }
};
