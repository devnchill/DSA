/*
Given an integer array nums, rotate the array to the right by k steps, where k
is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105
*/
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
class Solution {
public:
  // Method 1.
  void rotate(std::vector<int> &nums, int k) {
    size_t size = nums.size();
    k = k % size;
    std::vector<int> temp_arr(size);
    for (size_t i = 0; i < size; i++) {
      temp_arr[i] = nums[(i - k + size) % size];
    }
    nums = temp_arr;
  }

  // Method 2.
  void rotate2(std::vector<int> &nums, int k) {
    size_t size = nums.size();
    k = k % size;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
  }
};
int main(int argc, char *argv[]) {
  std::vector<int> nums = {7, 1, 2, 3, 4, 5, 6};
  Solution s;
  s.rotate(nums, 3);
  for (auto it : nums) {
    std::cout << it;
  }
  s.rotate(nums, 3);
  std::cout << std::endl;
  for (auto it : nums) {
    std::cout << it;
  }
  return 0;
}
