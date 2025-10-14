/*
1752. Check if Array Is Sorted and Rotated

Given an array nums, return true if the array was originally sorted in
non-decreasing order, then rotated some number of positions (including zero).
Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length
such that B[i] == A[(i+x) % A.length] for every valid index i.

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3:
[3,4,5,1,2].

Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
*/

#include <iostream>
#include <vector>
class Solution {
public:
  bool check(std::vector<int> &nums) {
    // array is sorted if current element >= previous element . but this would
    // violate the rotated array , so point of rotation could be found out where
    // current might less than previous value and atmost only 1 point should
    // exist.
    int count = 0;
    int length_of_vector = nums.size() - 1;
    for (size_t iterator = 0; iterator < length_of_vector; iterator++) {
      if (nums[iterator] > nums[(iterator + 1) % length_of_vector]) {
        count++;
      }
      if (count > 1)
        return false;
    }
    return true;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums1 = {2, 1, 4, 21, 4, 1, 1, 3, 4, 2, 9};
  std::vector<int> nums2 = {1, 2, 3, 4, 5};
  std::cout << s.check(nums1) << std::endl;
  std::cout << s.check(nums2) << std::endl;
  return 0;
}
