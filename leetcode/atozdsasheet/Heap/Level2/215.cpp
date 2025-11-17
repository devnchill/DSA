/*
215. Kth Largest Element in an Array
Medium
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, return the kth largest element in
the array.

Note that it is the kth largest element in the sorted order, not the kth
distinct element.

Can you solve it without sorting?



Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> p;
    for (int val : nums)
      p.push(val);
    for (int i = 1; i < k; i++)
      p.pop();
    return p.top();
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5};
  cout << s.findKthLargest(nums, 1);
  return 0;
}
