// 368. Largest Divisible Subset
// Medium
// Topics
// premium lock icon
// Companies
// Given a set of distinct positive integers nums, return the largest subset
// answer such that every pair (answer[i], answer[j]) of elements in this subset
// satisfies:
//
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.
//
//
//
// Example 1:
//
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:
//
// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
//
//
// Constraints:
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
    }
    int pointer = 0;
    for (int i = 1; i < n; i++) {
      if (dp[i] > dp[pointer])
        pointer = i;
    }
    vector<int> res;
    while (pointer != -1) {
      res.push_back(nums[pointer]);
      pointer = prev[pointer];
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
