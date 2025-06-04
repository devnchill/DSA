#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  // Brute-force method to find longest subarray with sum = k
  int longestSubarray(std::vector<int> &nums, int k) {
    int size = nums.size();
    int max_len = 0;

    for (int i = 0; i < size; ++i) {
      int sum = 0;
      for (int j = i; j < size; ++j) {
        sum += nums[j];
        if (sum == k) {
          max_len = std::max(max_len, j - i + 1);
        }
      }
    }

    return max_len;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {10, 5, 2, 7, 1, 9};
  std::cout << s.longestSubarray(nums, 17); // Expected output: 4
  return 0;
}
