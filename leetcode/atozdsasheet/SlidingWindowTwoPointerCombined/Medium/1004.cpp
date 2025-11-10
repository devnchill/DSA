/*
1004. Max Consecutive Ones III
Medium
Topics
premium lock icon
Companies
Hint
Given a binary array nums and an integer k, return the maximum number of
consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // METHOD 1
  // int longestOnes(vector<int> &nums, int k) {
  //   int start = 0;
  //   int curr_win_size = 0;
  //   int max_consecutive_one = 0;
  //   int n = nums.size();
  //   if (k >= n)
  //     return n;
  //   int temp = k;
  //   while (start < n && start + curr_win_size < n) {
  //     if (nums[start + curr_win_size] == 1) {
  //       curr_win_size++;
  //     } else if (nums[start + curr_win_size] == 0 && temp > 0) {
  //       temp--;
  //       curr_win_size++;
  //     } else {
  //       max_consecutive_one = max(max_consecutive_one, curr_win_size);
  //       start++;
  //       temp = k;
  //       curr_win_size = 0;
  //     }
  //   }
  //   max_consecutive_one = max(max_consecutive_one, curr_win_size);
  //   return max_consecutive_one;
  // }

  int longestOnes(vector<int> &nums, int k) {
    int left = 0;
    int zeros = 0;
    int max_len = 0;
    int n = nums.size();
    for (int right = 0; right < n; right++) {
      if (nums[right] == 0)
        zeros++;
      while (zeros > k) {
        if (nums[left] == 0)
          zeros--;
        left++;
      }
      max_len = max(max_len, right - left + 1);
    }
    return max_len;
  }
};

int main() {
  Solution s;
  vector<int> nums = {0, 0, 1, 1};
  cout << s.longestOnes(nums, 1);
}
