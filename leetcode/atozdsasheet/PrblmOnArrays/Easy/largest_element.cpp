/* Given an array of integers nums, return the value of the largest element in
the array.
Examples: Input: nums = [3, 3, 6, 1] Output: 6 Explanation: The
largest element in array is 6 Input: nums = [3, 3, 0, 99, -40] Output: 99
Explanation: The largest element in array is 99*/

#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;

class Solution {
public:
  // Method 1. Sort entire array and return the last number since that would be
  // the largest of all.
  int largestElementBySorting(std::vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return *(nums.end() - 1);
  }

  // Method 2 by iterating and comparing
  int largestElementByIterating(std::vector<int> &nums) {
    int max = nums[0];
    for (auto it : nums) {
      if (it > max) {
        max = it;
      }
    }
    return max;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {2, 33, 2, 222, -10};
  cout << s.largestElementBySorting(nums) << std::endl;
  cout << s.largestElementByIterating(nums) << std::endl;
  return 0;
}
