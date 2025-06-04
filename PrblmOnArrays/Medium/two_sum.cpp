/*1. Two Sum
Easy
Topics
Companies
Hint

Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]



Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/
#include <iostream>
#include <vector>
class Solution {
public:
  // Method 1.Brute force
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {3, 2, 4};
  std::vector<int> r = s.twoSum(nums, 6);
  for (auto it : r) {
    std::cout << it << std::endl;
  }
  return 0;
}
