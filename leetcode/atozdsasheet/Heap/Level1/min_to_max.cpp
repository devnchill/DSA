/*
Convert Min Heap to Max Heap

0

100
Medium

Given a min-heap in array representation named nums, convert it into a max-heap
and return the resulting array.



A min-heap is a complete binary tree where the key at the root is the minimum
among all keys present in a binary min-heap and the same property is recursively
true for all nodes in the Binary Tree.

A max-heap is a complete binary tree where the key at the root is the maximum
among all keys present in a binary max-heap and the same property is recursively
true for all nodes in the Binary Tree.



Since there can be multiple answers, the compiler will return true if it's
correct, else false.


Examples:
Input: nums = [10, 20, 30, 21, 23]

Output: [30, 21, 23, 10, 20]

Explanation:

Input: nums = [-5, -4, -3, -2, -1]

Output: [-1, -2, -3, -4, -5]

Explanation:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {

  void fix(int i, vector<int> &nums, int n) {
    while (true) {
      int largest = i;
      int left = 2 * i + 1;
      int right = 2 * i + 2;

      if (left < n && nums[left] > nums[largest])
        largest = left;

      if (right < n && nums[right] > nums[largest])
        largest = right;

      if (largest == i)
        break;

      swap(nums[i], nums[largest]);

      i = largest;
    }
  }

public:
  vector<int> minToMaxHeap(vector<int> nums) {
    int n = nums.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
      fix(i, nums, n);
    }
    return nums;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {10, 20, 30, 21, 23};
  vector<int> res = s.minToMaxHeap(nums);
  for (int val : res)
    cout << val << "\n";
  return 0;
}
