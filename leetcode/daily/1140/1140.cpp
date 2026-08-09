// 1140. Stone Game II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Alice and Bob continue their games with piles of stones. There are a number
// of piles arranged in a row, and each pile has a positive integer number of
// stones piles[i]. The objective of the game is to end with the most stones.
//
// Alice and Bob take turns, with Alice starting first.
//
// On each player's turn, that player can take all the stones in the first X
// remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M
// = 1.
//
// The game continues until all the stones have been taken.
//
// Assuming Alice and Bob play optimally, return the maximum number of stones
// Alice can get.
//
//
//
// Example 1:
//
// Input: piles = [2,7,9,4,4]
//
// Output: 10
//
// Explanation:
//
// If Alice takes one pile at the beginning, Bob takes two piles, then Alice
// takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total. If Alice
// takes two piles at the beginning, then Bob can take all three piles left. In
// this case, Alice get 2 + 7 = 9 stones in total. So we return 10 since it's
// larger.
//
// Example 2:
//
// Input: piles = [1,2,3,4,5,100]
//
// Output: 104
//
//
//
// Constraints:
//
// 1 <= piles.length <= 100
// 1 <= piles[i] <= 104

#include <bits/stdc++.h>
using namespace std;

// METHOD 1 Bruteforce
class Solution1 {
private:
  int get_stones(int i, int x, vector<int> &piles) {
    int stones = 0;
    for (int cnt = 0; cnt < x && i + cnt < piles.size(); cnt++) {
      stones += piles[i + cnt];
    }
    return stones;
  }

  int solve(bool isAliceTurn, int m, int i, vector<int> &piles) {
    if (i >= piles.size())
      return 0;
    int result;
    if (isAliceTurn)
      result = 0;
    else
      result = INT_MAX;
    for (int x = 1; x <= 2 * m && i + x <= piles.size(); x++) {
      int current = get_stones(i, x, piles);
      int future = solve(!isAliceTurn, max(m, x), i + x, piles);
      if (isAliceTurn) {
        result = max(result, current + future);
      } else {
        result = min(result, future);
      }
    }
    return result;
  }

public:
  int stoneGameII(vector<int> &piles) { return solve(true, 1, 0, piles); }
};

class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    int n = piles.size();

    // suffix[i] = total stones from i to end
    vector<int> suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
      suffix[i] = suffix[i + 1] + piles[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> solve = [&](int i, int M) -> int {
      if (i >= n)
        return 0;

      if (dp[i][M] != -1)
        return dp[i][M];

      // Can take all remaining piles
      if (2 * M >= n - i)
        return dp[i][M] = suffix[i];

      int best = 0;

      for (int x = 1; x <= 2 * M; x++) {
        // opponent's best from next state
        int opponent = solve(i + x, max(M, x));

        // current player's stones
        best = max(best, suffix[i] - opponent);
      }

      return dp[i][M] = best;
    };

    return solve(0, 1);
  }
};

int main() {
  Solution s;
  vector<int> piles = {2, 7, 9, 4, 4};
  cout << s.stoneGameII(piles);
}
