// 714. Best Time to Buy and Sell Stock with Transaction Fee
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array prices where prices[i] is the price of a given stock
// on the ith day, and an integer fee representing a transaction fee.
//
// Find the maximum profit you can achieve. You may complete as many
// transactions as you like, but you need to pay the transaction fee for each
// transaction.
//
// Note:
//
// You may not engage in multiple transactions simultaneously (i.e., you must
// sell the stock before you buy again). The transaction fee is only charged
// once for each stock purchase and sale.
//
//
// Example 1:
//
// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Example 2:
//
// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6
//
//
// Constraints:
//
// 1 <= prices.length <= 5 * 104
// 1 <= prices[i] < 5 * 104
// 0 <= fee < 5 * 104

#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<vector<int>> dp;
  int rec(vector<int> &prices, int fee, int i, bool can_buy) {
    if (i >= prices.size()) {
      return 0;
    }
    if (dp[i][can_buy] != -1)
      return dp[i][can_buy];
    if (can_buy) {
      return dp[i][can_buy] =
                 max(-prices[i] + rec(prices, fee, i + 1, !can_buy),
                     rec(prices, fee, i + 1, can_buy));
    } else {
      return dp[i][can_buy] =
                 max(prices[i] - fee + rec(prices, fee, i + 1, !can_buy),
                     rec(prices, fee, i + 1, can_buy));
    }
  }

public:
  int maxProfit(vector<int> &prices, int fee) {
    dp.resize(prices.size(), vector<int>(2, -1));
    return rec(prices, fee, 0, true);
  }
};
