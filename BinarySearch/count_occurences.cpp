/*
Problem Statement: You are given a sorted array containing N integers and a
number X, you have to find the occurrences of X in the given array.
Examples

Example 1:
Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
Explanation: 3 is occurring 4 times in
the given array so it is our answer.

Example 2:
Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
Explanation: 2 is occurring 5 times in the given array so it is our answer.
*/

#include <iostream>
#include <vector>

class Solution {
private:
  int first_occurence(std::vector<int> nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int res = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        res = mid;
        high = mid - 1;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }
  int last_occurence(std::vector<int> nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int res = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        res = mid;
        low = mid + 1;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }

public:
  int total_occurence(std::vector<int> nums, int target) {
    return (last_occurence(nums, target) - first_occurence(nums, target) + 1);
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3};
  Solution s;
  std::cout << s.total_occurence(nums, 2);
  return 0;
}
