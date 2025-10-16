
/*
29. Divide Two Integers
Medium
Topics
premium lock iconCompanies

Given two integers dividend and divisor, divide two integers without using
multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its
fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would
be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers
within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if
the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the
quotient is strictly less than -231, then return -231.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

Constraints:

    -231 <= dividend, divisor <= 231 - 1
    divisor != 0
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == divisor)
      return 1;
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;
    if (divisor == 1)
      return dividend;
    bool isPositive = true;
    if (dividend >= 0 && divisor < 0)
      isPositive = false;
    else if (dividend < 0 && divisor > 0)
      isPositive = false;
    long long n = dividend;
    long long d = divisor;
    n = abs(n);
    d = abs(d);
    long long ans = 0, sum = 0;
    while (sum + d <= n) {
      ans++;
      sum += d;
    }
    if (ans > INT_MAX && isPositive)
      return INT_MAX;
    if (ans > INT_MAX && !isPositive)
      return INT_MIN;
    return isPositive ? ans : -1 * ans;
  }
};

int main() {
  int dividend = 10, divisor = 3;
  Solution sol;
  int ans = sol.divide(dividend, divisor);
  cout << "The result of dividing " << dividend << " and " << divisor << " is "
       << ans;
  return 0;
}
