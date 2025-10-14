/*
Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
    1 <= nums.length <= 2 * 104
    -1000 <= nums[i] <= 1000
    -107 <= k <= 107
*/
#include <unordered_map>
#include <vector>
class Solution {
public:
  // Bruteforce approach
  int subarraySum(std::vector<int> &nums, int k) {
    std::vector<int> ps;
    std::pmr::unordered_map<int, int> m;
    int sum = 0;
    int count = 0;
    for (auto it : nums) {
      sum += it;
      ps.push_back(sum);
    }
    for (auto it : ps) {
      if (it == k)
        count++;
      int val = it - k;
      if (m.find(val) != m.end()) {
        count += m[val];
      }
      if (m.find(it) == m.end()) {
        m[it] = 0;
      }
      m[it]++;
    }
    return count;
  }
};
