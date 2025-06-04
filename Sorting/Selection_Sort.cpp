//**************************************************************************************************************************************
// Given an array of integers nums, sort the array in non-decreasing order using
// the selection sort algorithm and return the sorted array. A sorted array in
// non-decreasing order is an array where each element is greater than or equal
// to all previous elements in the array.
//***************************************************************************************************************************************

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> selectionSort(vector<int> &nums) {
    // Loop from start to end and increament starting postion with 1 each
    // iteration.
    for (size_t i = 0; i < nums.size(); i++) {
      // find minimum element and swap minimum with first element of current
      // array.
      int temp = 0, min_index = i;
      for (size_t j = i; j < nums.size(); j++) {
        if (nums[j] < nums[min_index]) {
          min_index = j;
        }
      }
      temp = nums[i];
      nums[i] = nums[min_index];
      nums[min_index] = temp;
    }
    return nums;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> arr = {2, 3, 1, 9, 6, 4};
  arr = s.selectionSort(arr);
  for (auto it : arr) {
    cout << it << endl;
  }
  return 0;
}
