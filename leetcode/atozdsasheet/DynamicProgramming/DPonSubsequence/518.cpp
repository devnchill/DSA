// 518. Coin Change II
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.
//
// Return the number of combinations that make up that amount. If that amount of
// money cannot be made up by any combination of the coins, return 0.
//
// You may assume that you have an infinite number of each kind of coin.
//
// The answer is guaranteed to fit into a signed 32-bit integer.
//
// Example 1:
//
// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:
//
// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:
//
// Input: amount = 10, coins = [10]
// Output: 1
//
//
// Constraints:
//
// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// All the values of coins are unique.
// 0 <= amount <= 5000

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  unordered_map<string, int> cache;
  int dfs(vector<int> &coins, int curr_index, int curr_amount, int target) {
    string key = to_string(curr_index) + "," + to_string(curr_amount);
    if (cache.count(key))
      return cache[key];
    if (target == curr_amount) {
      return cache[key] = 1;
    }
    if (curr_index < 0 || curr_amount > target) {
      return cache[key] = 0;
    }
    int exclude = dfs(coins, curr_index - 1, curr_amount, target);
    int include =
        dfs(coins, curr_index, curr_amount + coins[curr_index], target);
    return cache[key] = include + exclude;
  }

public:
  int change(int amount, vector<int> &coins) {
    return dfs(coins, coins.size() - 1, 0, amount);
  }
};
