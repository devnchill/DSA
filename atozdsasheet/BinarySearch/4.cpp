/* Given two sorted arrays nums1 and nums2 of size m and n respectively, return
the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106

*/

#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> merged;
    merged.reserve(nums1.size() + nums2.size());

    merged.insert(merged.end(), nums1.begin(), nums1.end());
    merged.insert(merged.end(), nums2.begin(), nums2.end());

    std::sort(merged.begin(), merged.end());
    int n = merged.size();

    if (n % 2 == 0) {
      return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    } else {
      return merged[n / 2];
    }
  }
};

#include <iostream>

int main() {
  Solution s;
  vector<int> nums1 = {2};
  vector<int> nums2 = {1, 3};
  std::cout << s.findMedianSortedArrays(nums1, nums2);
  return 0;
}
