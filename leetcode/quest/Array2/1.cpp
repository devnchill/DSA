/*
Q1. Set Mismatch
Easy
Topics
premium lock icon
Companies
You have a set of integers s, which originally contains all the numbers from 1
to n. Unfortunately, due to some error, one of the numbers in s got duplicated
to another number in the set, which results in repetition of one number and loss
of another number.

You are given an integer array nums representing the data status of this set
after the error.

Find the number that occurs twice and the number that is missing and return them
in the form of an array.



Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]


Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // METHOD 1
  // vector<int> findErrorNums(vector<int> &nums) {
  //   int loss = -1, duplicate = -1;
  //   int n = nums.size();
  //   unordered_map<int, int> m;
  //   for (int &val : nums)
  //     m[val]++;
  //   for (int i = 1; i <= n; i++) {
  //     if (m.find(i) == m.end())
  //       loss = i;
  //     else if (m[i] == 2)
  //       duplicate = i;
  //   }
  //   return {duplicate, loss};
  // }

  // METHOD 2
  // vector<int> findErrorNums(vector<int> &nums) {
  //   sort(nums.begin(), nums.end());
  //   int n = nums.size();
  //   int loss = -1, duplicate = -1;
  //   for (int i = 0; i < n; i++) {
  //     if (i != 0 && nums[i] - nums[i - 1] == 0)
  //       duplicate = nums[i];
  //     if (i != 0 && nums[i] - nums[i - 1] == 2)
  //       loss = nums[i] - 1;
  //   }
  //   if (nums[0] != 1)
  //     loss = 1;
  //   if (nums[n - 1] != n && loss == -1)
  //     loss = n;
  //   return {duplicate, loss};
  // }

  // METHOD 3
  vector<int> findErrorNums(vector<int> &nums) {
    int val = 0;
    for (int i = 0; i < nums.size(); i++) {
      val ^= nums[i];
      val ^= (i + 1);
    }
    int rightmost_set_bit = val & -val;
    vector<int> group1;
    vector<int> group2;
    int v1 = 0, v2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] & rightmost_set_bit)
        v1 = v1 ^ nums[i];
      else
        v2 = v2 ^ nums[i];
    }
    for (int i = 1; i <= nums.size(); i++) {
      if (i & rightmost_set_bit)
        v1 = v1 ^ i;
      else
        v2 = v2 ^ i;
    }
    if (find(nums.begin(), nums.end(), v1) == nums.end())
      return {v2, v1};
    else
      return {v1, v2};
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 2, 4};
  auto res = s.findErrorNums(nums);
  for (int &val : res)
    cout << val;
  return 0;
}
