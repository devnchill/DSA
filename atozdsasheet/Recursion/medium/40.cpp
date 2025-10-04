/*40. Combination Sum II
Medium
Topics
premium lock iconCompanies

Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers
sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]

Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> group;
    sort(candidates.begin(), candidates.end()); // must sort for duplicates
    backtrack(res, candidates, group, 0, 0, target);
    return res;
  }

private:
  void backtrack(vector<vector<int>> &res, vector<int> &candidates,
                 vector<int> &group, int currentSum, int index, int target) {
    if (currentSum == target) {
      res.push_back(group);
      return;
    }
    if (index >= candidates.size() || currentSum > target)
      return;
    group.push_back(candidates[index]);
    backtrack(res, candidates, group, currentSum + candidates[index], index + 1,
              target);
    group.pop_back();
    int nextIndex = index + 1;
    while (nextIndex < candidates.size() &&
           candidates[nextIndex] == candidates[index]) {
      nextIndex++;
    }
    backtrack(res, candidates, group, currentSum, nextIndex, target);
  }
};
