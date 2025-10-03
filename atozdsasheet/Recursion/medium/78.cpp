/*
Given an integer array nums of unique elements, return all possible

(the power set).

The solution set must not contain duplicate subsets. Return the solution in any
order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int index = 0;
    vector<vector<int>> res = {};
    vector<int> curr = {};
    backtrack(index, res, nums, curr);
    return res;
  }

private:
  void backtrack(int index, vector<vector<int>> &res, vector<int> &nums,
                 vector<int> &temp) {
    if (index == nums.size()) {
      res.push_back(temp);
      return;
    }
    backtrack(index + 1, res, nums, temp);
    temp.push_back(nums[index]);
    backtrack(index + 1, res, nums, temp);
    temp.pop_back();
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v = {1, 2, 3, 4};
  vector<vector<int>> res = s.subsets(v);
  for (auto it : res) {
    for (auto jit : it) {
      cout << jit;
    }
    cout << endl;
  }
  return 0;
}
