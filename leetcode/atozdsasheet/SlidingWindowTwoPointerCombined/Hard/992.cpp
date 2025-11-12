/*
992. Subarrays with K Different Integers
Hard
Topics
premium lock icon
Companies
Hint
Given an integer array nums and an integer k, return the number of good
subarrays of nums.

A good array is an array where the number of different integers in that array is
exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1],
[1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2] Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
[2,1,3], [1,3,4].


Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  int slidingWindowWithAtMost(int k, vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> freq_map;
    int left = 0, total_count = 0;
    for (int right = 0; right < n; right++) {
      freq_map[nums[right]]++;
      while (freq_map.size() > k) {
        freq_map[nums[left]]--;
        if (freq_map[nums[left]] == 0)
          freq_map.erase(nums[left]);
        left++;
      }
      total_count += (right - left + 1);
    }
    return total_count;
  }

public:
  // METHOD 1. BRUTEFORCE
  // int subarraysWithKDistinct(vector<int> &nums, int k) {
  //   int n = nums.size();
  //   int res = 0;
  //   for (int i = 0; i < n; i++) {
  //     vector<int> sub_arr;
  //     unordered_set<int> s;
  //     for (int j = i; j < n; j++) {
  //       sub_arr.push_back(nums[j]);
  //       s.insert(nums[j]);
  //       if (j - i + 1 < k)
  //         continue;
  //       if (s.size() == k)
  //         res++;
  //     }
  //   }
  //   return res;
  // }

  // METHOD 2. Use solver(n)-solver(n-1) trick
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return slidingWindowWithAtMost(k, nums) -
           slidingWindowWithAtMost(k - 1, nums);
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 1, 3, 4};
  cout << s.subarraysWithKDistinct(nums, 3);
  return 0;
}
