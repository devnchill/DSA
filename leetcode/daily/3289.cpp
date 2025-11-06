/*
3289. The Two Sneaky Numbers of Digitville
Easy
Topics
premium lock icon
Companies
Hint
In the town of Digitville, there was a list of numbers called nums containing
integers from 0 to n - 1. Each number was supposed to appear exactly once in the
list, however, two mischievous numbers sneaked in an additional time, making the
list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an
array of size two containing the two numbers (in any order), so peace can return
to Digitville.



Example 1:

Input: nums = [0,1,1,0]

Output: [0,1]

Explanation:

The numbers 0 and 1 each appear twice in the array.

Example 2:

Input: nums = [0,3,2,1,3,2]

Output: [2,3]

Explanation:

The numbers 2 and 3 each appear twice in the array.

Example 3:

Input: nums = [7,1,5,4,3,4,6,0,9,5,8,2]

Output: [4,5]

Explanation:

The numbers 4 and 5 each appear twice in the array.



Constraints:

2 <= n <= 100
nums.length == n + 2
0 <= nums[i] < n
The input is generated such that nums contains exactly two repeated elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // METHOD 1
  // vector<int> getSneakyNumbers(vector<int> &nums) {
  //   vector<int> res;
  //   unordered_map<int, int> m;
  //   for (int &val : nums) {
  //     if (m[val] == 1) {
  //       res.push_back(val);
  //     } else
  //       m[val]++;
  //   }
  //   return res;
  // }

  // METHOD 2

  vector<int> getSneakyNumbers(vector<int> &nums) {
    vector<int> res;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      int cur = nums[i];
      int val;
      if (cur == -n)
        val = 0;
      else if (cur < 0)
        val = -cur;
      else
        val = cur;
      if (nums[val] < 0 || nums[val] == -n) {
        res.push_back(val);
      } else {
        nums[val] = (nums[val] == 0) ? -n : -nums[val];
      }
    }

    return res;
  }
};
