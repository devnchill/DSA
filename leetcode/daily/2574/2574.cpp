// 2574. Left and Right Sum Differences
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed integer array nums of size n.
//
// Define two arrays leftSum and rightSum where:
//
// leftSum[i] is the sum of elements to the left of the index i in the array
// nums. If there is no such element, leftSum[i] = 0. rightSum[i] is the sum of
// elements to the right of the index i in the array nums. If there is no such
// element, rightSum[i] = 0. Return an integer array answer of size n where
// answer[i] = |leftSum[i] - rightSum[i]|.
//
//
//
// Example 1:
//
// Input: nums = [10,4,8,3]
// Output: [15,1,11,22]
// Explanation: The array leftSum is [0,10,14,22] and the array rightSum is
// [15,11,3,0]. The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] =
// [15,1,11,22]. Example 2:
//
// Input: nums = [1]
// Output: [0]
// Explanation: The array leftSum is [0] and the array rightSum is [0].
// The array answer is [|0 - 0|] = [0].
//
//
// Constraints:
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 105

#include <bits/stdc++.h>
using namespace std;

// METHOD 1
class Solution1 {
public:
  vector<int> leftRightDifference(vector<int> &nums) {
    int n = nums.size();
    vector<int> left_sum, right_sum;
    vector<int> res;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    left_sum.push_back(0);
    right_sum.push_back(sum - nums[0]);
    res.push_back(abs(left_sum[0] - right_sum[0]));

    for (int i = 1; i < n; i++) {
      left_sum.push_back(left_sum[i - 1] + nums[i - 1]);
      right_sum.push_back(sum - left_sum[i] - nums[i]);
      res.push_back(abs(left_sum[i] - right_sum[i]));
    }
    return res;
  }
};

// METHOD 2
class Solution {
public:
  vector<int> leftRightDifference(vector<int> &nums) {
    int n = nums.size();
    vector<int> res;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0;
    int right_sum = sum - nums[0];
    res.push_back(abs(left_sum - right_sum));

    for (int i = 1; i < n; i++) {
      left_sum += nums[i - 1];
      right_sum -= nums[i];
      res.push_back(abs(left_sum - right_sum));
    }
    return res;
  }
};
