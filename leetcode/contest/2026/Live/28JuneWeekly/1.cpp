#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maxSum(vector<int> &nums, int k, int mul) {
    sort(nums.begin(), nums.end(), greater<int>());
    long long sum = 0;
    for (int i = 0; i < k; i++) {
      sum += mul > 0 ? nums[i] * mul : nums[i];
      mul--;
    }
    return sum;
  }
};

int main() {
  Solution s;
  vector<int> nums = {6, 1, 2, 9};
  cout << s.maxSum(nums, 3, 2);
}
