#include <iostream>
#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int count = 0;
    int j = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      while (nums[i] == nums[i + 1]) {
        i++;
      }
      nums[j] = nums[i];
      j++;
      count++;
    }
    return count;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {1, 1, 3, 3, 4, 4, 4};
  int k = s.removeDuplicates(nums);
  std::cout << k << std::endl;
  return 0;
}
