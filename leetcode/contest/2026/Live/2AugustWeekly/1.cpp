// Q1. Maximize Pair Strength Using GCD
// Easy
// 3 pt.
// You are given an integer array nums.
//
// Choose exactly one pair of distinct indices i and j. The strength of the pair
// is defined as (nums[i] * nums[j]) / gcd(nums[i], nums[j])2.
//
// Return the maximum strength over all possible pairs.
//
// The term gcd(a, b) denotes the greatest common divisor of a and b.
//
//  
//
// Example 1:
//
// Input: nums = [2,3,5]
//
// Output: 15
//
// Explanation:
//
// Choosing i = 1 and j = 2 gives strength (3 * 5) / gcd(3, 5)2 = 15 / 1 = 15,
// which is the maximum over all pairs.
//
// Example 2:
//
// Input: nums = [4,6,8]
//
// Output: 12
//
// Explanation:
//
// Choosing i = 1 and j = 2 gives strength (6 * 8) / gcd(6, 8)2 = 48 / 4 = 12,
// which is the maximum over all pairs.
//
// Example 3:
//
// Input: nums = [3,3]
//
// Output: 1
//
// Explanation:
//
// Choosing i = 0 and j = 1 gives strength (3 * 3) / gcd(3, 3)2 = 9 / 9 = 1, the
// maximum over all pairs.
//
//  
//
// Constraints:
//
// 2 <= nums.length <= 2000
// 1 <= nums[i] <= 105
//  
// ©leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long get_gcd(long long f, long long s) {
    if (s == 0)
      return f;
    return get_gcd(s, f % s);
  }

public:
  long long maxPairStrength(vector<int> &nums) {
    int n = nums.size();
    long long res = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        long long f = nums[i], s = nums[j];
        long long p = 1LL * nums[i] * nums[j];
        long long gcd = get_gcd(f, s);
        long long gcd_sq = gcd * gcd;
        long long curr_ans = p / gcd_sq;
        res = max(res, curr_ans);
      }
    }
    return res;
  }
};
