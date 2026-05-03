#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> countOppositeParity(vector<int> &nums) {
    int n = nums.size();
    vector<int> suffix_odd(n, 0);
    vector<int> suffix_even(n, 0);
    for (int i = n - 2; i >= 0; i--) {
      suffix_even[i] = suffix_even[i + 1] + (nums[i + 1] % 2 == 0 ? 1 : 0);
      suffix_odd[i] = suffix_odd[i + 1] + (nums[i + 1] % 2 == 0 ? 0 : 1);
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
      if (nums[i] % 2 == 0)
        res[i] = suffix_odd[i];
      else
        res[i] = suffix_even[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  auto res = s.countOppositeParity(nums);
  for (auto val : res)
    cout << val << "\n";
}
