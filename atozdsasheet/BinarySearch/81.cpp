/*
 There is an integer array nums sorted in non-decreasing order (not necessarily
with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index
k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1],
..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example,
[0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become
[4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if
target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Constraints:

    1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    nums is guaranteed to be rotated at some pivot.
    -104 <= target <= 104

*/
#include <iostream>
#include <vector>
using std::pmr::vector;
class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int size = nums.size();
    int low = 0;
    int mid = -1;
    int high = size - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (target == nums[mid])
        return true;
      if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
        ++low;
        --high;
        continue;
      } else if (nums[low] <= nums[mid]) {
        // left half is sorted
        if (target >= nums[low] && target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (target > nums[mid] && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return false;
  }
};
;

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  std::cout << s.search(nums, 2);
  return 0;
}
