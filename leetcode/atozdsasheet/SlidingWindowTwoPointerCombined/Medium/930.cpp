/*
930. Binary Subarrays With Sum
Medium
Topics
premium lock icon
Companies
Given a binary array nums and an integer goal, return the number of non-empty
subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15


Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  // public:
  // METHOD 1 BRUTEFORCE
  // generate subarray and calc and check if its equal to goal
  // int numSubarraysWithSum(vector<int> &nums, int goal) {
  //   int result = 0;
  //   int n = nums.size();
  //   for (int i = 0; i < n; i++) {
  //     vector<int> subarr;
  //     for (int j = i; j < n; j++) {
  //       subarr.push_back(nums[j]);
  //       if (accumulate(subarr.begin(), subarr.end(), 0) == goal)
  //         result++;
  //     }
  //   }
  //   return result;
  // }

  // METHOD 2
  int helper(int x, vector<int> &nums) {
    if (x < 0)
      return 0;
    int n = nums.size();
    int l = 0, curr = 0;
    int res = 0;
    for (int r = 0; r < n; r++) {
      curr += nums[r];
      while (curr > x) {
        curr -= nums[l];
        l++;
      }
      res += (r - l + 1);
    }
    return res;
  }

public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    return helper(goal, nums) - helper(goal - 1, nums);
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 1, 1, 0, 1};
  cout << s.numSubarraysWithSum(nums, 2);
  return 0;
}
