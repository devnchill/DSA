#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
class Solution {
public:
  // Method 1 --> Sort and return second last element.
  int secondLargestElementBySorting(std::vector<int> &nums) {
    // your code goes here
    sort(nums.begin(), nums.end());
    int max = nums[nums.size() - 1];
    // Last 2 elements could be the same as well so instead of blindly returning
    // second last element , checking if it's same as largest and if not then
    // return that otherwise if every element are same return -1.
    for (size_t i = nums.size() - 2; i <= 0; i++) {
      if (nums[i] != max) {
        return nums[i];
      }
    }
    return -1;
  }

  // Method 2. --> element less than largest but greater than others.
  int secondLargestElementByIteration(std::vector<int> &nums) {
    int max = *(nums.begin());
    int s_largest = INT_MIN;
    // calc max first.
    for (auto it : nums) {
      if (it > max)
        max = it;
    }
    for (auto it : nums) {
      if (it > s_largest && it < max)
        s_largest = it;
    }
    return s_largest;
  }

  // Method 3. --> second largest would be last max value of if value is greater
  // than second max and less than max.
  int secondLargestELementByReplacing(std::vector<int> &nums) {
    int max = nums[0];
    int slmax = -1;
    for (auto it : nums) {
      if (it > max) {
        slmax = max;
        max = it;
      } else if (it < max && it > slmax) {
        slmax = it;
      }
    }
    return slmax;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {2, 33, 2, 222, -10};
  std::cout << s.secondLargestElementByIteration(nums) << std::endl;
  std::cout << s.secondLargestElementByIteration(nums);
  return 0;
}
