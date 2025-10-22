/*
503. Next Greater Element II
Medium
Topics
premium lock icon
Companies
Given a circular integer array nums (i.e., the next element of nums[nums.length
- 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its
traversing-order next in the array, which means you could search circularly to
find its next greater number. If it doesn't exist, return -1 for this number.



Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]


Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    size_t n = nums.size();
    vector<int> res(n, -1);
    for (size_t i = 0; i < n; i++) {
      bool found = false;
      for (size_t j = i + 1; j < n; j++) {
        if (nums[j] > nums[i]) {
          found = true;
          res[i] = nums[j];
          break;
        }
      }
      if (!found)
        for (size_t j = 0; j < i; j++) {
          if (nums[j] > nums[i]) {
            res[i] = nums[j];
            break;
          }
        }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 3};
  vector<int> res = s.nextGreaterElements(nums);
  cout << "[";
  for (int val : res) {
    cout << val << ",";
  }
  cout << "]";
  return 0;
}
