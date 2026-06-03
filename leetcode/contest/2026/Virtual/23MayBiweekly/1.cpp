// Q1. Minimum Swaps to Move Zeros to End
// Easy
// 3 pt.
// You are given an integer array nums.
//
// In one operation, you can choose any two distinct indices i and j and swap
// nums[i] and nums[j].
//
// Return an integer denoting the minimum number of operations required to move
// all 0s to the end of the array.
//
//
//
// Example 1:
//
// Input: nums = [0,1,0,3,12]
//
// Output: 2
//
// Explanation:
//
// We perform the following swap operations:
//
// Swap nums[0] and nums[3], giving nums = [3, 1, 0, 0, 12].
// Swap nums[2] and nums[4], giving nums = [3, 1, 12, 0, 0].
// Thus, the answer is 2.
//
// Example 2:
//
// Input: nums = [0,1,0,2]
//
// Output: 1
//
// Explanation:
//
// We perform the following swap operations:
//
// Swap nums[0] and nums[3], giving nums = [2, 1, 0, 0].
// Thus, the answer is 1.
//
// Example 3:
//
// Input: nums = [1,2,0]
//
// Output: 0
//
// Explanation:
//
// The array already satisfies the condition. Therefore, no swap operations are
// needed.
//
//
//
// Constraints:
//
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumSwaps(vector<int> &nums) {
    int first = 0, last = nums.size() - 1;
    int res = 0;
    while (first < last) {
      while (nums[last] == 0)
        last--;
      if (nums[first] == 0)
        swap(nums[first], nums[last]), res++;
      else
        first++;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 0};
  cout << s.minimumSwaps(nums);
}
