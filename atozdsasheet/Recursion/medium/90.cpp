/*
90. Subsets II
Medium
Topics
premium lock iconCompanies

Given an integer array nums that may contain duplicates, return all possible

(the power set).

The solution set must not contain duplicate subsets. Return the solution in any
order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> subset;
    sort(nums.begin(), nums.end());
    backtrack(nums, 0, subset, res);
    return res;
  }

private:
  void backtrack(vector<int> &nums, int start, vector<int> &subset,
                 vector<vector<int>> &res) {
    res.push_back(subset);
    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i] == nums[i - 1])
        continue;

      subset.push_back(nums[i]);
      backtrack(nums, i + 1, subset, res);
      subset.pop_back();
    }
  }
};
