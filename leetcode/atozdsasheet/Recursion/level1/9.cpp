// find max in array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int get_max_element(vector<int> &nums, int i, int N, int max) {
    if (i == N)
      return max;
    if (max < nums[i])
      max = nums[i];
    return get_max_element(nums, i + 1, N, max);
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 8, 3};
  cout << s.get_max_element(nums, 0, nums.size(), INT_MIN) << "\n";
  return 0;
}
