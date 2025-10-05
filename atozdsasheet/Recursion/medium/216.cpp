/*
216. Combination Sum III
Medium
Topics
premium lock iconCompanies

Find all valid combinations of k numbers that sum up to n such that the
following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the
same combination twice, and the combinations may be returned in any order.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is
1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> candidate = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> res;
    vector<int> currCombination;
    backtrack(res, candidate, currCombination, k, n, 0, 0);
    return res;
  }

private:
  void backtrack(vector<vector<int>> &res, vector<int> &candidate,
                 vector<int> &currCombination, int k, int n, int index,
                 int currSum) {
    if (currCombination.size() == k) {
      if (currSum == n)
        res.push_back(currCombination);
      return;
    }

    for (int i = index; i < candidate.size(); ++i) {
      if (currSum + candidate[i] > n)
        break;
      currCombination.push_back(candidate[i]);
      backtrack(res, candidate, currCombination, k, n, i + 1,
                currSum + candidate[i]);
      currCombination.pop_back();
    }
  }
};
