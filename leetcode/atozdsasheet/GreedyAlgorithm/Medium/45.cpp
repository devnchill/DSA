/*
45. Jump Game II
Medium
Topics
premium lock icon
Companies
You are given a 0-indexed array of integers nums of length n. You are initially
positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index
i. In other words, if you are at index i, you can jump to any index (i + j)
where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are
generated such that you can reach index n - 1.



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1
step from index 0 to 1, then 3 steps to the last index. Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/
#include <bits/stdc++.h>
#include <climits>
using namespace std;
class Solution {
private:
  vector<int> memoize;
  int getJump(int pointer, int endpoint, vector<int> &nums) {
    if (pointer >= endpoint)
      return 0;
    if (nums[pointer] == 0)
      return -1;

    if (memoize[pointer] != -2)
      return memoize[pointer];

    int min_jump = INT_MAX;
    int max_jump = nums[pointer];
    for (int i = max_jump; i >= 1; i--) {
      int res = getJump(pointer + i, endpoint, nums);
      if (res != -1)
        min_jump = min(min_jump, 1 + res);
    }
    memoize[pointer] = (min_jump == INT_MAX) ? -1 : min_jump;
    return memoize[pointer];
  }

public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    memoize.assign(n, -2);
    return getJump(0, n - 1, nums);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v = {2, 3, 1, 1, 4};
  cout << s.jump(v);
  return 0;
}
