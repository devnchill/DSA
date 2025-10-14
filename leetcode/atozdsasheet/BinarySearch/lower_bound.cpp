/*
Problem Statement: Given a sorted array of N integers and an integer x, write a
program to find the lower bound of x. Example 1: Input Format: N = 4, arr[] =
{1,2,2,3}, x = 2 Result: 1 Explanation: Index 1 is the smallest index such that
arr[1] >= x.

Example 2:
Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
*/

#include <iostream>
#include <vector>
class Solution {
public:
  int find_lower_bound(std::vector<int> nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        while (nums[mid - 1] == target) {
          mid--;
        }
        return mid;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {1, 2, 3, 3, 3, 3, 5, 5, 6, 7, 8, 9};
  std::cout << s.find_lower_bound(nums, 5);
  return 0;
}
