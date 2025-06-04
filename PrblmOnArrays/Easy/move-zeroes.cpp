#include <iostream>
#include <vector>
class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    int i = 0;
    for (auto it : nums) {
      if (it != 0) {
        nums[i++] = it;
      }
    }
    for (; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};
int main(int argc, char *argv[]) {
  std::vector<int> nums = {2, 0, 2, 0, 54, 59, 12, 0, 9};
  Solution s;
  s.moveZeroes(nums);
  for (auto it : nums) {
    std::cout << it << std::endl;
  }
  return 0;
}
