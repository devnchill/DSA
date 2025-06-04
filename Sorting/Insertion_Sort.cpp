//***************************************************************************************************************************************
// Given an array of integers called nums, sort the array in non-decreasing
// order using the insertion sort algorithm and return the sorted array. A
// sorted array in non-decreasing order is an array where each element is
// greater than or equal to all preceding elements in the array. Examples:
// Input: nums = [7, 4, 1, 5, 3]
// Explanation: 1 <= 3 <= 4 <= 5 <= 7.
// Thus the array is sorted in non-decreasing order.
// Input: nums = [5, 4, 4, 1, 1]
// Output: [1, 1, 4, 4, 5]
// Explanation: 1 <= 1 <= 4 <= 4 <= 5.
// Thus the array is sorted in non-decreasing order.
//***************************************************************************************************************************************
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> insertionSort(vector<int> &nums) {
    for (size_t i = 1; i < nums.size(); i++) {
      int key = nums[i];
      int j = i - 1;
      // Shift elements of nums[0..i-1], that are greater than key, to one
      // position ahead
      while (j >= 0 && nums[j] > key) {
        nums[j + 1] = nums[j];
        j--;
      }
      nums[j + 1] = key;
    }
    return nums;
  }
};
