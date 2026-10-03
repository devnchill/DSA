/*
* 3350. Adjacent Increasing Subarrays Detection II
Medium
Topics
premium lock iconCompanies
Hint

Given an array nums of n integers, your task is to find the maximum value of k
for which there exist two adjacent

of length k each, such that both subarrays are strictly increasing.
Specifically, check if there are two subarrays of length k starting at indices a
and b (a < b), where:

    Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly
increasing. The subarrays must be adjacent, meaning b = a + k.

Return the maximum possible value of k.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [2,5,7,8,9,2,3,4,3,1]

Output: 3

Explanation:

    The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
    The subarray starting at index 5 is [2, 3, 4], which is also strictly
increasing. These two subarrays are adjacent, and 3 is the maximum possible
value of k for which two such adjacent strictly increasing subarrays exist.

Example 2:

Input: nums = [1,2,3,4,4,4,4,5,6,7]

Output: 2

Explanation:

    The subarray starting at index 0 is [1, 2], which is strictly increasing.
    The subarray starting at index 2 is [3, 4], which is also strictly
increasing. These two subarrays are adjacent, and 2 is the maximum possible
value of k for which two such adjacent strictly increasing subarrays exist.

Constraints:

    2 <= nums.length <= 2 * 105
    -109 <= nums[i] <= 109
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxIncreasingSubarrays(vector<int> &nums) {
    int len = nums.size();
    if (len <= 2)
      return 1;
    vector<int> inc(len, 1);
    for (int i = len - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1])
        inc[i] = inc[i + 1] + 1;
      else
        inc[i] = 1;
    }

    int low = 1;
    int mid;
    int high = len / 2;
    int res = 0;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (canExistForK(mid, nums, inc, len)) {
        res = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }

private:
  bool canExistForK(int k, vector<int> &nums, vector<int> &inc, int len) {
    for (int i = 0; i + 2 * k <= len; i++) {
      if (inc[i] >= k && inc[i + k] >= k)
        return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
  cout << s.maxIncreasingSubarrays(v);
  return 0;
}
