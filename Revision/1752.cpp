/*
* Given an array nums, return true if the array was originally sorted in
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
using std::pmr::vector;
class Solution {
public:
  bool check(vector<int> &nums) {
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] < nums[i])
        count++;
    }
    return count > 1 ? false : true;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {5, 6, 7, 8, 1, 2, 3, 4};
  vector<int> nums2 = {8, 6, 7, 8, 1, 2, 3, 4};
  vector<int> nums3 = {5, 5, 6, 7, 8, 1, 2, 3, 4};
  bool res = s.check(nums);
  bool res2 = s.check(nums2);
  bool res3 = s.check(nums3);
  std::cout << res << std::endl;
  std::cout << res2 << std::endl;
  std::cout << res3 << std::endl;
  return 0;
}
