/*
* 238. Product of Array Except Self
Medium
Topics
premium lock iconCompanies
Hint

Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.

You must write an algorithm that runs in O(n) time and without using the
division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:

    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The input is generated such that answer[i] is guaranteed to fit in a 32-bit
integer.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int len = nums.size();
    vector<int> prefixProduct(len);
    vector<int> suffixProduct(len);
    prefixProduct[0] = 1;
    suffixProduct[len - 1] = 1;
    int preProd = nums[0];
    for (int i = 1; i < len; i++) {
      prefixProduct[i] = preProd;
      preProd *= nums[i];
    }
    int sProd = 1;
    for (int i = len - 1; i >= 0; i--) {
      suffixProduct[i] = sProd;
      sProd *= nums[i];
    }
    vector<int> res;
    for (int i = 0; i < len; i++) {
      res.push_back(prefixProduct[i] * suffixProduct[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 3, 4};
  vector<int> res = s.productExceptSelf(v);
  for (auto it : res) {
    cout << it << endl;
  }
  return 0;
}
