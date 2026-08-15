// 3702. Longest Subsequence With Non-Zero Bitwise XOR
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums.
//
// Return the length of the longest subsequence in nums whose bitwise XOR is
// non-zero. If no such subsequence exists, return 0.
//
//
//
// Example 1:
//
// Input: nums = [1,2,3]
//
// Output: 2
//
// Explanation:
//
// One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 =
// 1, which is non-zero.
//
// Example 2:
//
// Input: nums = [2,3,4]
//
// Output: 3
//
// Explanation:
//
// The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3
// XOR 4 = 5, which is non-zero.
//
//
//
// Constraints:
//
// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
private:
  int res = 0;
  void rec(vector<int> &arr, int i, int xr, int sub_len) {
    if (sub_len > 0 && xr > 0) {
      res = max(res, sub_len);
    }
    if (i == arr.size())
      return;
    rec(arr, i + 1, xr ^ arr[i], sub_len + 1);
    rec(arr, i + 1, xr, sub_len);
  }

public:
  int longestSubsequence(vector<int> &nums) {
    rec(nums, 0, 0, 0);
    return res;
  }
};

class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int xr = 0;
    bool hasNonZero = false;
    for (int x : nums) {
      xr ^= x;
      if (x != 0)
        hasNonZero = true;
    }
    if (xr != 0)
      return nums.size();
    return hasNonZero ? nums.size() - 1 : 0;
  }
};
int main() {
  Solution s;
  vector<int> nums = {2, 3, 4};
  cout << s.longestSubsequence(nums);
}
