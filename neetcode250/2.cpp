/*
* Contains Duplicate

Given an integer array nums, return true if any value appears more than once in
the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
*/

#include <iostream>
#include <map>
#include <vector>
using std::pmr::map;
using std::pmr::vector;

class Solution {
public:
  bool hasDuplicate(vector<int> &nums) {
    // Method 1. O(n^2)
    // for (int i = 0; i < nums.size(); i++) {
    //   for (int j = i + 1; j < nums.size(); j++) {
    //     if (nums[i] == nums[j]) {
    //       return true;
    //     }
    //   }
    // }
    // return false;
    // Method 2. O(n) space for hashmap. o(n) time complexity
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(nums[i]) == m.end()) {
        m[nums[i]] = 1;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {1, 1, 2, 3};
  std::cout << s.hasDuplicate(nums);
  return 0;
}
