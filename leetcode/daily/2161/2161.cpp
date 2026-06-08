// 2161. Partition Array According to Given Pivot
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed integer array nums and an integer pivot. Rearrange
// nums such that the following conditions are satisfied:
//
// Every element less than pivot appears before every element greater than
// pivot. Every element equal to pivot appears in between the elements less than
// and greater than pivot. The relative order of the elements less than pivot
// and the elements greater than pivot is maintained. More formally, consider
// every pi, pj where pi is the new position of the ith element and pj is the
// new position of the jth element. If i < j and both elements are smaller (or
// larger) than pivot, then pi < pj. Return nums after the rearrangement.
//
//
//
// Example 1:
//
// Input: nums = [9,12,5,10,14,3,10], pivot = 10
// Output: [9,5,3,10,10,12,14]
// Explanation:
// The elements 9, 5, and 3 are less than the pivot so they are on the left side
// of the array. The elements 12 and 14 are greater than the pivot so they are
// on the right side of the array. The relative ordering of the elements less
// than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are
// the respective orderings. Example 2:
//
// Input: nums = [-3,4,3,2], pivot = 2
// Output: [-3,2,4,3]
// Explanation:
// The element -3 is less than the pivot so it is on the left side of the array.
// The elements 4 and 3 are greater than the pivot so they are on the right side
// of the array. The relative ordering of the elements less than and greater
// than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
//
//
// Constraints:
//
// 1 <= nums.length <= 105
// -106 <= nums[i] <= 106
// pivot equals to an element of nums.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> less, equal, high;
    int pi = -1;
    for (size_t i = 0; i < nums.size(); i++) {
      int curr = nums[i];
      if (curr == pivot) {
        if (pi == -1)
          pi = i;
        equal.push_back(curr);
      } else if (curr < pivot)
        less.push_back(nums[i]);
      else
        high.push_back(nums[i]);
    }
    int less_i = 0;
    int equal_i = 0;
    int high_i = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (less_i < less.size())
        nums[i] = less[less_i], less_i++;
      else if (equal_i < equal.size())
        nums[i] = equal[equal_i], equal_i++;
      else if (high_i < high.size())
        nums[i] = high[high_i], high_i++;
    }
    return nums;
  }
};

int main() {
  Solution s;
  vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
  auto res = s.pivotArray(nums, 10);
  for (int val : res)
    cout << val << "\n";
}
