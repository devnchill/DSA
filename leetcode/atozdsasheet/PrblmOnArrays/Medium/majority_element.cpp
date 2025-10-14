#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
  // Brute force method
  // Sort the vector and return mid/closest to mid element
  int majorityElement1(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }

  // Method 2
  int majorityElement2(std::vector<int> &nums) {
    int candidate = 0;
    int count = 0;
    for (int it : nums) {
      if (count == 0) {
        count = 1;
        candidate = it;
      } else if (it == candidate) {
        count++;
      } else {
        count--;
      }
    }
    return candidate;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {1, 1, 1, 1, 6, 8, 3, 4, 1};
  std::cout << s.majorityElement2(nums);
  return 0;
}
