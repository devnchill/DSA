// 1674. Minimum Moves to Make Array Complementary
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums of even length n and an integer limit. In
// one move, you can replace any integer from nums with another integer between
// 1 and limit, inclusive.
//
// The array nums is complementary if for all indices i (0-indexed), nums[i] +
// nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is
// complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.
//
// Return the minimum number of moves required to make nums complementary.
//
//
//
// Example 1:
//
// Input: nums = [1,2,4,3], limit = 4
// Output: 1
// Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements
// are changed). nums[0] + nums[3] = 1 + 3 = 4. nums[1] + nums[2] = 2 + 2 = 4.
// nums[2] + nums[1] = 2 + 2 = 4.
// nums[3] + nums[0] = 3 + 1 = 4.
// Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
// Example 2:
//
// Input: nums = [1,2,2,1], limit = 2
// Output: 2
// Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change
// any number to 3 since 3 > limit. Example 3:
//
// Input: nums = [1,2,1,2], limit = 2
// Output: 0
// Explanation: nums is already complementary.
//
//
// Constraints:
//
// n == nums.length
// 2 <= n <= 105
// 1 <= nums[i] <= limit <= 105
// n is even.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minMoves(vector<int> &nums, int limit) {
    int n = nums.size();
    unordered_map<int, int> sum_count;
    vector<int> min_arr, max_arr;
    min_arr.reserve(n / 2);
    max_arr.reserve(n / 2);

    for (int i = 0; i < n / 2; ++i) {
      int a = std::min(nums[i], nums[n - 1 - i]);
      int b = std::max(nums[i], nums[n - 1 - i]);

      sum_count[a + b]++;
      min_arr.push_back(a);
      max_arr.push_back(b);
    }

    std::sort(min_arr.begin(), min_arr.end());
    std::sort(max_arr.begin(), max_arr.end());

    int min_ops = n;

    for (int c = 2; c <= 2 * limit; ++c) {
      int add_left = n / 2 - (lower_bound(min_arr.begin(), min_arr.end(), c) -
                              min_arr.begin());
      int add_right = lower_bound(max_arr.begin(), max_arr.end(), c - limit) -
                      max_arr.begin();

      int current_ops = n / 2 + add_left + add_right - sum_count[c];
      min_ops = min(min_ops, current_ops);
    }

    return min_ops;
  }
};
