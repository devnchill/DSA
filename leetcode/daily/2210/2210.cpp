/*
2110. Number of Smooth Descent Periods of a Stock
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array prices representing the daily price history of a
stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such
that the price on each day is lower than the price on the preceding day by
exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.



Example 1:

Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
Example 2:

Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.
Example 3:

Input: prices = [1]
Output: 1
Explanation: There is 1 smooth descent period: [1]


Constraints:

1 <= prices.length <= 105
1 <= prices[i] <= 105
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long getDescentPeriods(vector<int> &prices) {
    int first = 0;
    int n = prices.size();
    long long res = 0;
    for (int second = 0; second < n; second++) {
      if (second == n - 1) {
        res += 1LL * (second - first + 1) * (second - first + 2) / 2;
        break;
      }
      if (prices[second] - prices[second + 1] == 1) {
        continue;
      }
      res += (second - first + 1) * (second - first + 2) / 2;
      first = second + 1;
    }
    return res;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> prices = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 4, 3, 10, 9, 8, 7};
  cout << s.getDescentPeriods(prices);
  return 0;
}
