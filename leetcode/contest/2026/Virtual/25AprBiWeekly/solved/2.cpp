#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int compareBitonicSums(vector<int> &nums) {
    int n = nums.size();
    int peak = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] > nums[i + 1]) {
        peak = i;
        break;
      }
    }
    long long sum_one = 0;
    long long sum_two = 0;
    for (int i = 0; i <= peak; i++) {
      sum_one += nums[i];
    }
    for (int i = peak; i < n; i++) {
      sum_two += nums[i];
    }
    if (sum_one == sum_two)
      return -1;
    else if (sum_one > sum_two)
      return 0;
    else
      return 1;
  }
};
