/*
55. Jump Game
Medium
Topics
premium lock icon
Companies
You are given an integer array nums. You are initially positioned at the array's
first index, and each element in the array represents your maximum jump length
at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump
length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> m;
  bool check(int pointer, int endpoint, vector<int> &nums) {
    if (pointer >= endpoint)
      return true;

    if (m[pointer] != -1)
      return m[pointer];
    int max_jump = min(nums[pointer], endpoint - pointer);
    for (int j = max_jump; j >= 1; j--)
      if (check(pointer + j, endpoint, nums)) {
        return m[pointer] = 1;
      };
    return m[pointer] = 0;
  }

public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    m.assign(n, -1);
    return check(0, n - 1, nums);
  }
};

int main() {
  Solution s;
  vector<int> n = {3, 2, 1, 0, 4};
  cout << s.canJump(n);
  return 0;
}
