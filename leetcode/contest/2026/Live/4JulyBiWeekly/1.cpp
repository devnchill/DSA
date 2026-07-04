#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isMiddleElementUnique(vector<int> &nums) {
    int n = nums.size();
    int mid = nums[n / 2];
    for (int i = 0; i < n; i++) {
      if (nums[i] == mid && i < n / 2)
        return false;
      if (nums[i] == mid && i > n / 2)
        return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 3, 3};
  cout << s.isMiddleElementUnique(nums);
}
