#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDigitRange(vector<int> &nums) {
    vector<vector<int>> a(10);
    for (int n : nums) {
      string num = to_string(n);
      int mi = 9, ma = 0;
      for (char ch : num) {
        mi = min(mi, ch - '0');
        ma = max(ma, ch - '0');
      }
      a[ma - mi].push_back(n);
    }
    for (int i = a.size() - 1; i >= 0; i--) {
      int sum = 0;
      if (!a[i].empty()) {
        for (int n : a[i])
          sum += n;
        return sum;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums = {90, 900};
  cout << s.maxDigitRange(nums);
}
