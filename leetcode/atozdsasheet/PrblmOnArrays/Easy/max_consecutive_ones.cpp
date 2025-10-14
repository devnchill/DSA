#include <algorithm>
#include <vector>

class Solution {
public:
  int findMaxConsecutiveOnes(std::vector<int> &nums) {
    int max_count = 0, current = 0;
    for (int n : nums) {
      if (n == 1) {
        current++;
        max_count = std::max(max_count, current);
      } else {
        current = 0;
      }
    }
    return max_count;
  }
};
