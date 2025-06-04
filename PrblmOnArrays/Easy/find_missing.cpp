#include <numeric>
#include <vector>
class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    int size = nums.size();
    // sum of numbers from 0 to size
    int expected_sum = (size * (size + 1)) / 2;
    int actual_sum = std::accumulate(nums.begin(), nums.end(), 0);
    return expected_sum - actual_sum;
  }
};
