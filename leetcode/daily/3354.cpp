/*
3354. Make Array Elements Equal to Zero
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and
choose a movement direction of either left or right.

After that, you repeat the following process:

If curr is out of the range [0, n - 1], this process ends.
If nums[curr] == 0, move in the current direction by incrementing curr if you
are moving right, or decrementing curr if you are moving left. Else if
nums[curr] > 0: Decrement nums[curr] by 1. Reverse your movement direction (left
becomes right and vice versa). Take a step in your new direction. A selection of
the initial position curr and movement direction is considered valid if every
element in nums becomes 0 by the end of the process.

Return the number of possible valid selections.

Example 1:

Input: nums = [1,0,2,0,3]

Output: 2

Explanation:

The only possible valid selections are the following:

Choose curr = 3, and a movement direction to the left.
[1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,3] -> [1,0,1,0,2] ->
[1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [1,0,0,0,1] ->
[1,0,0,0,1] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] ->
[0,0,0,0,1] -> [0,0,0,0,0]. Choose curr = 3, and a movement direction to the
right. [1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,2,0,2] -> [1,0,1,0,2]
-> [1,0,1,0,2] -> [1,0,1,0,1] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] ->
[1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [0,0,0,0,0]. Example
2:

Input: nums = [2,3,4,0,4,1,0]

Output: 0

Explanation:

There are no possible valid selections.

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
There is at least one element i where nums[i] == 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  //   METHOD 1 BRUTE FORCE
  //   int countValidSelections(vector<int> &nums) {
  //     int res = 0;
  //     int n = nums.size();
  //     for (int i = 0; i < n; i++) {
  //       int curr = i;
  //       if (nums[curr] == 0) {
  //         vector<int> left = nums;
  //         vector<int> right = nums;
  //         if (check_left(curr, left, n))
  //           res++;
  //         if (check_right(curr, right, n))
  //           res++;
  //       }
  //     }
  //     return res;
  //   }
  //
  // private:
  //   bool check_left(int curr, vector<int> &nums, int n) {
  //     int dir = -1;
  //     while (curr >= 0 && curr < n) {
  //       if (nums[curr] > 0) {
  //         nums[curr]--;
  //         dir *= -1;
  //       }
  //       curr += dir;
  //     }
  //     return is_valid(nums);
  //   }
  //
  //   bool check_right(int curr, vector<int> &nums, int n) {
  //     int dir = 1;
  //     while (curr >= 0 && curr < n) {
  //       if (nums[curr] > 0) {
  //         nums[curr]--;
  //         dir *= -1;
  //       }
  //       curr += dir;
  //     }
  //     return is_valid(nums);
  //   };
  //
  //   bool is_valid(vector<int> &nums) {
  //     bool is_valid = true;
  //     for (int &val : nums)
  //       if (val != 0) {
  //         is_valid = false;
  //         break;
  //       }
  //     return is_valid;
  //   }

  // METHOD 2
  int countValidSelections(vector<int> &nums) {
    int res = 0;
    int n = nums.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    int pleft = 0;
    int nright = 0;
    for (int i = 0; i < n; i++) {
      left[i] = nums[i] + pleft;
      pleft += nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      right[i] = nums[i] + nright;
      nright += nums[i];
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        if (left[i] == right[i]) {
          res += 2;
        } else if (abs(left[i] - right[i]) == 1) {
          res++;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {16, 13, 10, 0, 0, 0, 10, 6, 7, 8, 7};
  cout << s.countValidSelections(nums);
  return 0;
}
