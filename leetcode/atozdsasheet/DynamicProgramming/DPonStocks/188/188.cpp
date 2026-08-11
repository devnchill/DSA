// 188. Best Time to Buy and Sell Stock IV
// Hard
// Topics
// premium lock icon
// Companies
// You are given an integer array prices where prices[i] is the price of a given
// stock on the ith day, and an integer k.
//
// Find the maximum profit you can achieve. You may complete at most k
// transactions: i.e. you may buy at most k times and sell at most k times.
//
// Note: You may not engage in multiple transactions simultaneously (i.e., you
// must sell the stock before you buy again).
//
//
//
// Example 1:
//
// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
// 4-2 = 2. Example 2:
//
// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
// 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit
// = 3-0 = 3.
//
//
// Constraints:
//
// 1 <= k <= 100
// 1 <= prices.length <= 1000
// 0 <= prices[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<vector<int>>> dp;
  int rec(vector<int> &prices, size_t i, bool can_buy, size_t num_transaction,
          size_t k) {
    if (i == prices.size() || num_transaction == k)
      return 0;
    if (dp[i][can_buy][num_transaction] != -1)
      return dp[i][can_buy][num_transaction];
    if (can_buy) {
      return dp[i][can_buy][num_transaction] = max(
                 -prices[i] + rec(prices, i + 1, !can_buy, num_transaction, k),
                 rec(prices, i + 1, can_buy, num_transaction, k));
    } else {
      return dp[i][can_buy][num_transaction] =
                 max(prices[i] +
                         rec(prices, i + 1, !can_buy, num_transaction + 1, k),
                     rec(prices, i + 1, can_buy, num_transaction, k));
    }
  }

public:
  int maxProfit(int k, vector<int> &prices) {
    dp.resize(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return rec(prices, 0, true, 0, k);
  }
};

int main() {
  Solution s;
  vector<int> prices = {3, 2, 6, 5, 0, 3};
  cout << s.maxProfit(2, prices);
}
