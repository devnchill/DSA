// 123. Best Time to Buy and Sell Stock III
// Hard
// Topics
// premium lock icon
// Companies
// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.
//
// Find the maximum profit you can achieve. You may complete at most two
// transactions.
//
// Note: You may not engage in multiple transactions simultaneously (i.e., you
// must sell the stock before you buy again).
//
//
//
// Example 1:
//
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
// 3-0 = 3. Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit
// = 4-1 = 3. Example 2:
//
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
// 5-1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later,
// as you are engaging multiple transactions at the same time. You must sell
// before buying again. Example 3:
//
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
//
// Constraints:
//
// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105

#include <bits/stdc++.h>
using namespace std;

// MEHOD 1
class Solution1 {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> left(n), right(n);
    int left_min = INT_MAX, left_profit = 0;
    int right_max = 0, right_profit = 0;
    for (int i = 0; i < n; i++) {
      left_min = min(left_min, prices[i]);
      left_profit = max(left_profit, prices[i] - left_min);
      left[i] = left_profit;
    }
    for (int i = n - 1; i >= 0; i--) {
      right_max = max(right_max, prices[i]);
      right_profit = max(right_profit, right_max - prices[i]);
      right[i] = right_profit;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = max(left[i] + right[i], res);
    }
    return res;
  }
};

// MEHOD w
class Solution {
private:
  vector<vector<vector<int>>> dp;
  int solve(int i, bool can_buy, vector<int> &prices,
            int no_of_transactions_done) {
    if (no_of_transactions_done == 2)
      return 0;
    if (i == prices.size())
      return 0;
    if (dp[i][can_buy][no_of_transactions_done] != -1)
      return dp[i][can_buy][no_of_transactions_done];
    int profit = 0;
    if (can_buy) {
      int buy =
          -prices[i] + solve(i + 1, false, prices, no_of_transactions_done);
      int skip = solve(i + 1, true, prices, no_of_transactions_done);
      profit = max(buy, skip);
    } else {
      int sell =
          prices[i] + solve(i + 1, true, prices, no_of_transactions_done + 1);
      int skip = solve(i + 1, false, prices, no_of_transactions_done);
      profit = max(sell, skip);
    }
    return dp[i][can_buy][no_of_transactions_done] = profit;
  }

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    dp.resize(n, vector<vector<int>>(2, vector<int>(2, -1)));
    return solve(0, true, prices, 0);
  }
};
