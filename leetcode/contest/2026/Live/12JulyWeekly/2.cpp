#include <bits/stdc++.h>
using namespace std;

class Solution {
  long long MOD = 1e9 + 7;

public:
  int minimumCost(vector<int> &nums, int k) {
    long long curr = k;
    long long count = 0;
    for (int val : nums) {
      if (curr < val) {
        long long a = (val - curr + k - 1LL) / k;
        count += a;
        curr += a * k;
      }
      curr -= val;
    }
    long long ans = 0;
    if (count % 2 == 0) {
      ans = ((count / 2) % MOD) * ((count + 1) % MOD);
    } else {
      ans = (count % MOD) * (((count + 1) / 2) % MOD);
    }
    return ans % MOD;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 1, 7, 14};
  cout << s.minimumCost(nums, 4);
}
