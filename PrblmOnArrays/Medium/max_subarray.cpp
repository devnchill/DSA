/*Given an integer array nums, find the

with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
*/

#include <algorithm>
#include <vector>
class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int size = nums.size();
    int sum_of_subarray = nums[0];
    for (size_t i = 0; i < size; i++) {
      int curr_sum = 0;
      for (size_t j = i; j < size; j++) {
        curr_sum = curr_sum + nums[j];
        sum_of_subarray = std::max(sum_of_subarray, curr_sum);
      }
    }
    return sum_of_subarray;
  }

  // Method 2.

  int maxSubArray2(std::vector<int> &nums) {
    int current_sum = nums[0];
    int maximum_sum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
      int it = nums[i];
      current_sum = std::max(it, current_sum + it);
      maximum_sum = std::max(maximum_sum, current_sum);
    }
    return maximum_sum;
  }
};
