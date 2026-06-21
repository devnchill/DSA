#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countValidSubarrays(vector<int> &nums, int x) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
      prefix[i + 1] = prefix[i] + nums[i];

    int ans = 0;

    for (int l = 0; l < n; l++) {
      for (int r = l; r < n; r++) {
        long long sum = prefix[r + 1] - prefix[l];

        if (sum % 10 != x)
          continue;

        long long first = sum;
        while (first >= 10)
          first /= 10;

        if (first == x)
          ans++;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 100, 1};
  cout << s.countValidSubarrays(nums, 1) << "\n";
}
