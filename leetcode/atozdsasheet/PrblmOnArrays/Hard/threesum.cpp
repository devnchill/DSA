/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not
matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105

*/
#include <algorithm>
#include <iostream>
#include <vector>
using std::pmr::vector;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int l = nums.size();
    vector<vector<int>> res;
    for (int a = 0; a < l - 2; a++) {
      if (a > 0 && nums[a] == nums[a - 1])
        continue;
      int i = a + 1, j = l - 1;
      while (i < j) {
        int sum = nums[a] + nums[i] + nums[j];
        if (sum == 0) {
          res.push_back({nums[a], nums[i], nums[j]});
          while (i < j && nums[i] == nums[i + 1])
            i++;
          while (i < j && nums[j] == nums[j - 1])
            j--;
          i++;
          j--;
        } else if (sum < 0) {
          i++;
        } else {
          j--;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution s;
  vector<vector<int>> res = s.threeSum(nums);
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[0].size(); j++) {
      std::cout << res[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}
