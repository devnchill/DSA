#include <iostream>
#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    int right_pointer = 0;
    for (int left_pointer = 0; left_pointer < n - 1; left_pointer++) {
      if (nums[left_pointer] != nums[left_pointer + 1]) {
        nums[right_pointer++] = nums[left_pointer];
      }
    }
    nums[right_pointer++] = nums[n - 1];
    return right_pointer;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 4};
  int k = s.removeDuplicates(nums);
  std::cout << k << std::endl;
  for (auto it : nums) {
    std::cout << it;
  }
  return 0;
}
