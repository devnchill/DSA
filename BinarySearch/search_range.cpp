/*
34. Find First and Last Position of Element in Sorted Array
Medium
Topics
premium lock iconCompanies

Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109

*/

#include <iostream>
#include <vector>
class Solution {
public:
  int findFirst(const std::vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        result = mid;
        high = mid - 1;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return result;
  }

  int findLast(const std::vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        result = mid;
        low = mid + 1;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return result;
  }

  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    return {first, last};
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {5, 7, 7, 8, 8, 10};
  std::vector<int> res = s.searchRange(nums, 8);
  for (auto it : res) {
    std::cout << it << std::endl;
  }
  return 0;
}
