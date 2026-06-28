#include <bits/stdc++.h>
using namespace std;

class Solution {
  using ll = long long;
  const ll NEG = -(1LL << 60);

public:
  long long solve(vector<int> &nums, int k, bool multiply) {
    auto modify = [&](int x) -> ll {
      if (multiply)
        return 1LL * x * k;
      if (x >= 0)
        return x / k;
      return -((-x) / k);
    };
    ll dp0 = nums[0];
    ll dp1 = modify(nums[0]);
    ll dp2 = NEG;

    ll ans = max(dp0, dp1);
    for (int i = 1; i < nums.size(); i++) {
      ll x = nums[i];
      ll y = modify(nums[i]);
      ll ndp0 = max(x, dp0 + x);
      ll ndp1 = max({y, dp0 + y, dp1 + y});
      ll ndp2 = max(dp1 + x, dp2 + x);

      dp0 = ndp0;
      dp1 = ndp1;
      dp2 = ndp2;
      ans = max({ans, dp0, dp1, dp2});
    }
    return ans;
  }

  long long maxSubarraySum(vector<int> &nums, int k) {
    return max(solve(nums, k, true), solve(nums, k, false));
  }
};
