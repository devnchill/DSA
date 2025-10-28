/*
2104. Sum of Subarray Ranges
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums. The range of a subarray of nums is the
difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.


Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Method 1
  // long long subArrayRanges(vector<int> &nums) {
  //   long long sum = 0;
  //   for (size_t i = 0; i < nums.size(); i++) {
  //     vector<int> substr;
  //     for (size_t j = i; j < nums.size(); j++) {
  //       substr.push_back(nums[j]);
  //       int max_val = *max_element(substr.begin(), substr.end());
  //       int min_val = *min_element(substr.begin(), substr.end());
  //       sum += max_val - min_val;
  //     }
  //   }
  //   return sum;
  // }

  // METHOD 2
  long long subArrayRanges(vector<int> &nums) {
    int n = nums.size();
    long long sum = 0;
    vector<int> ps = getPS(nums, n);
    vector<int> ns = getNS(nums, n);
    vector<int> pl = getPL(nums, n);
    vector<int> nl = getNL(nums, n);
    for (int i = 0; i < n; i++) {
      long long l = (i - pl[i]) * (nl[i] - i);
      long long s = (i - ps[i]) * (ns[i] - i);
      sum += (l - s) * nums[i];
    }
    return sum;
  }

private:
  vector<int> getPS(vector<int> &nums, int n) {
    stack<int> stk;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        stk.push(i);
        continue;
      }
      while (!stk.empty() && nums[stk.top()] > nums[i]) {
        stk.pop();
      }
      res[i] = stk.empty() ? -1 : stk.top();
      stk.push(i);
    }
    return res;
  }

  vector<int> getNS(vector<int> &nums, int n) {
    stack<int> stk;
    vector<int> res(n, n);
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) {
        stk.push(i);
        continue;
      }
      while (!stk.empty() && nums[stk.top()] >= nums[i]) {
        stk.pop();
      }
      res[i] = stk.empty() ? n : stk.top();
      stk.push(i);
    }
    return res;
  }
  vector<int> getPL(vector<int> &nums, int n) {
    stack<int> stk;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        stk.push(i);
        continue;
      }
      while (!stk.empty() && nums[stk.top()] < nums[i]) {
        stk.pop();
      }
      res[i] = stk.empty() ? -1 : stk.top();
      stk.push(i);
    }
    return res;
  }
  vector<int> getNL(vector<int> &nums, int n) {
    stack<int> stk;
    vector<int> res(n, n);
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) {
        stk.push(i);
        continue;
      }
      while (!stk.empty() && nums[stk.top()] <= nums[i]) {
        stk.pop();
      }
      res[i] = stk.empty() ? n : stk.top();
      stk.push(i);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {4, -2, -3, 4, 1};
  long long res = s.subArrayRanges(nums);
  cout << res;
}
