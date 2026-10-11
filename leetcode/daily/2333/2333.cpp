// 2333. Minimum Sum of Squared Difference
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given two positive 0-indexed integer arrays nums1 and nums2, both of
// length n.
//
// The sum of squared difference of arrays nums1 and nums2 is defined as the sum
// of (nums1[i] - nums2[i])2 for each 0 <= i < n.
//
// You are also given two positive integers k1 and k2. You can modify any of the
// elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any
// of the elements of nums2 by +1 or -1 at most k2 times.
//
// Return the minimum sum of squared difference after modifying array nums1 at
// most k1 times and modifying array nums2 at most k2 times.
//
// Note: You are allowed to modify the array elements to become negative
// integers.
//
//
//
// Example 1:
//
// Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
// Output: 579
// Explanation: The elements in nums1 and nums2 cannot be modified because k1 =
// 0 and k2 = 0. The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3
// - 20)2 + (4 - 19)2 = 579. Example 2:
//
// Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
// Output: 43
// Explanation: One way to obtain the minimum sum of square difference is:
// - Increase nums1[0] once.
// - Increase nums2[2] once.
// The minimum of the sum of square difference will be:
// (2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
// Note that, there are other ways to obtain the minimum of the sum of square
// difference, but there is no way to obtain a sum smaller than 43.
//
//
// Constraints:
//
// n == nums1.length == nums2.length
// 1 <= n <= 105
// 0 <= nums1[i], nums2[i] <= 105
// 0 <= k1, k2 <= 109

#include <bits/stdc++.h>
using namespace std;

// Gives TLE as O(n + log n)
class Solution1 {
public:
  long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1,
                             int k2) {
    int n = nums1.size();
    priority_queue<int, vector<int>> diff;
    for (int i = 0; i < n; i++) {
      diff.push(abs(nums1[i] - nums2[i]));
    }
    long long k = 1LL * k1 + k2;
    while (k--) {
      int top = diff.top();
      diff.pop();
      if (top == 0) {
        diff.push(0);
        break;
      }
      diff.push(top - 1);
    }
    long long res = 0;
    while (!diff.empty()) {
      long long val = diff.top();
      diff.pop();
      res += val * val;
    }
    return res;
  }
};

class Solution {
public:
  long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1,
                             int k2) {
    int n = nums1.size();
    vector<int> diff;
    for (int i = 0; i < n; i++) {
      diff.push_back(abs(nums1[i] - nums2[i]));
    }
    sort(diff.begin(), diff.end());
    long long k = 1LL * k1 + k2;
    long long low = 0;
    long long high = diff.back();
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      long long ops = 0;
      for (int i = n - 1; i >= 0; i--) {
        if (diff[i] <= mid)
          break;
        ops += diff[i] - mid;
      }
      if (ops <= k) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    long long threshold = low;
    for (int i = n - 1; i >= 0; i--) {
      if (diff[i] > threshold) {
        k -= diff[i] - threshold;
        diff[i] = threshold;
      }
    }
    for (int i = n - 1; i >= 0 && k > 0; i--) {
      if (diff[i] > 0) {
        diff[i]--;
        k--;
      }
    }

    long long ans = 0;
    for (long long x : diff) {
      ans += x * x;
    }

    return ans;
  }
};
;

int main() {
  Solution s;
  vector<int> num1 = {1, 4, 10, 12};
  vector<int> num2 = {5, 8, 6, 9};
  cout << s.minSumSquareDiff(num1, num2, 1, 1);
}
