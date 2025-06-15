/*
 Problem Statement: You're given an sorted array arr of n integers and an
integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the
largest element in the array which is smaller than or equal to x. The ceiling of
x is the smallest element in the array greater than or equal to x.

Pre-requisite: Lower Bound & Binary Search

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array
is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array
is also 8.
*/

#include <iostream>
#include <vector>
class Solution {
public:
  std::vector<int> find_floor_and_cel(std::vector<int> nums, int target) {
    int low = 0, high = nums.size() - 1;
    int floor = -1, ceil = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        floor = nums[mid];
        ceil = nums[mid];
        break;
      } else if (nums[mid] < target) {
        floor = nums[mid];
        low = mid + 1;
      } else {
        ceil = nums[mid];
        high = mid - 1;
      }
    }
    return {floor, ceil};
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {3, 4, 4, 7, 8, 10};
  std::vector<int> res = s.find_floor_and_cel(nums, 6);
  for (auto it : res) {
    std::cout << it << std::endl;
  }
  return 0;
}
