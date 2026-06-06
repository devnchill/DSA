#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maxTotal(vector<int> &nums, string s) {
    int n = nums.size();
    if (n == 1) {
      return s[0] == '1' ? nums[0] : 0;
    }
    auto cover0 = [&](int x1) -> long long {
      bool covered = (s[0] == '1') || (s[1] == '1' && x1 == 0);
      return covered ? nums[0] : 0;
    };

    auto contrib = [&](int pos, int xi, int xnext) -> long long {
      bool covered =
          (s[pos] == '1' && xi == 1) || (s[pos + 1] == '1' && xnext == 0);

      return covered ? nums[pos] : 0;
    };

    long long dp[2], ndp[2];

    dp[0] = cover0(0);
    dp[1] = cover0(1);

    for (int i = 1; i <= n - 2; i++) {
      ndp[0] = ndp[1] = -1e18;

      for (int xi = 0; xi <= 1; xi++) {
        for (int xnext = 0; xnext <= 1; xnext++) {
          ndp[xnext] = max(ndp[xnext], dp[xi] + contrib(i, xi, xnext));
        }
      }

      dp[0] = ndp[0];
      dp[1] = ndp[1];
    }

    long long ans = 0;

    for (int last = 0; last <= 1; last++) {
      bool covered = (s[n - 1] == '1' && last == 1);

      ans = max(ans, dp[last] + (covered ? nums[n - 1] : 0));
    }

    return ans;
  }
};
