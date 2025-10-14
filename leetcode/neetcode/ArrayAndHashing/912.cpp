/*
912. Sort an Array
Medium
Topics
premium lock iconCompanies

Given an array of integers nums, sort the array in ascending order and return
it.

You must solve the problem without using any built-in functions in O(nlog(n))
time complexity and with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not
changed (for example, 2 and 3), while the positions of other numbers are changed
(for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.

Constraints:

    1 <= nums.length <= 5 * 104
    -5 * 104 <= nums[i] <= 5 * 104

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void mergeSort(vector<int> &nums, int low, int high) {
    if (low >= high)
      return;

    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
  }

  void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
      if (nums[left] <= nums[right])
        temp.push_back(nums[left++]);
      else
        temp.push_back(nums[right++]);
    }

    while (left <= mid)
      temp.push_back(nums[left++]);
    while (right <= high)
      temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++) {
      nums[i] = temp[i - low];
    }
  }
};
