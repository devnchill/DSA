/*
1248. Count Number of Nice Subarrays
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is
called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.



Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // METHOD 1 Generate all subarray and check for the condition O(n^2)
  // int numberOfSubarrays(vector<int> &nums, int k) {
  //   int n = nums.size();
  //   int res = 0;
  //   for (int i = 0; i < n; i++) {
  //     vector<int> subarr;
  //     for (int j = i; j < n; j++) {
  //       if (nums[j] % 2 == 1)
  //         subarr.push_back(nums[j]);
  //       if (subarr.size() == k)
  //         res++;
  //     }
  //   }
  //   return res;
  // }
  int numberOfSubarrays(vector<int> &nums, int k) {
    int res = 0, odd = 0;
    int left = 0, mid = 0, right;
    for (int right = 0; right < nums.size(); right++) {
      if (nums[right] % 2 == 1)
        odd++;
      while (odd > k) {
        if (nums[left] % 2 == 1)
          odd--;
        left++;
        mid = left;
      }
      if (odd == k) {
        while (nums[mid] % 2 == 0)
          mid++;
        res += (mid - left) + 1;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {2, 4, 6};
  cout << s.numberOfSubarrays(nums, 1);
  return 0;
}
