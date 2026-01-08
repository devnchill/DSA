/*
1390. Four Divisors
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return the sum of divisors of the integers in that
array that have exactly four divisors. If there is no such integer in the array,
return 0.

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int sumFourDivisors(vector<int> &nums) {
    int res = 0;

    for (int n : nums) {
      int cnt = 0, sum = 0;
      for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
          int j = n / i;
          cnt++;
          sum += i;
          if (j != i) {
            cnt++;
            sum += j;
          }
          if (cnt > 4)
            break;
        }
      }
      if (cnt == 4)
        res += sum;
    }
    return res;
  }
};
