/*
1018. Binary Prefix Divisible By 5
Easy
Topics
premium lock icon
Companies
Hint
You are given a binary array nums (0-indexed).

We define xi as the number whose binary representation is the subarray
nums[0..i] (from most-significant-bit to least-significant-bit).

For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
Return an array of booleans answer where answer[i] is true if xi is divisible
by 5.



Example 1:

Input: nums = [0,1,1]
Output: [true,false,false]
Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and 3
in base-10. Only the first number is divisible by 5, so answer[0] is true.
Example 2:

Input: nums = [1,1,1]
Output: [false,false,false]


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  // BRUTEFORCE gives overflow error for some reason
  int binary_to_decimal(vector<int> &nums, int end) {
    int res = 0;
    int k = 0;
    for (int i = end; i >= 0; i--) {
      res += nums[i] * (pow(2, k));
      k++;
    }
    return res;
  }

public:
  // Simply impossible since i can't build such big size of bits and also
  // iterate over it while building everytime vector<bool>
  // prefixesDivBy5(vector<int> &nums) {
  //   vector<bool> answer;
  //   for (int i = 0; i < nums.size(); i++) {
  //     int decimal_value = binary_to_decimal(nums, i);
  //     answer.push_back(decimal_value % 5 == 0);
  //   }
  //   return answer;
  // }

  vector<bool> prefixesDivBy5(vector<int> &nums) {
    vector<bool> answer;
    int prefix = 0;
    int length = nums.size();
    for (int i = 0; i < length; i++) {
      prefix = ((prefix << 1) + nums[i]) % 5;
      answer.emplace_back(prefix == 0);
    }
    return answer;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {1, 1, 1};
  vector<bool> res = s.prefixesDivBy5(nums);
  for (bool val : res)
    cout << val;
  return 0;
}
