/*
3346. Maximum Frequency of an Element After Performing Operations I
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each
operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing
the operations.

Example 1:

Input: nums = [1,4,5], k = 1, numOperations = 2

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1]. nums becomes [1, 4, 5].
Adding -1 to nums[2]. nums becomes [1, 4, 4].
Example 2:

Input: nums = [5,11,20,20], k = 5, numOperations = 1

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1].

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
0 <= k <= 105
0 <= numOperations <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    int maxEl = *max_element(begin(nums), end(nums)) + k;
    vector<int> freq(maxEl + 1, 0);
    for (int &num : nums) {
      freq[num]++;
    }
    for (int i = 1; i <= maxEl; i++) {
      freq[i] += freq[i - 1];
    }
    int result = 0;
    for (int target = 0; target <= maxEl; target++) {
      if (freq[target] == 0)
        continue;
      int leftNum = max(0, target - k);
      int rightNum = min(target + k, maxEl);
      int totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);
      int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);
      int needConversion = totalCount - targetCount;
      int maxPossibleFreq = targetCount + min(numOperations, needConversion);
      result = max(result, maxPossibleFreq);
    }
    return result;
  }
};
