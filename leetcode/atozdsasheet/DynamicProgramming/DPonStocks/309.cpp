#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<int>> dp;
  int rec(vector<int> &prices, int i, bool can_buy) {
    if (i >= prices.size()) {
      return 0;
    }
    if (dp[i][can_buy] != -1)
      return dp[i][can_buy];
    if (can_buy) {
      return dp[i][can_buy] = max(-prices[i] + rec(prices, i + 1, !can_buy),
                                  rec(prices, i + 1, can_buy));
    } else {
      return dp[i][can_buy] = max(prices[i] + rec(prices, i + 2, !can_buy),
                                  rec(prices, i + 1, can_buy));
    }
  }

public:
  int maxProfit(vector<int> &prices) {
    dp.resize(prices.size(), vector<int>(2, -1));
    return rec(prices, 0, true);
  }
};
