/*
907. Sum of Subarray Minimums
Medium
Topics
premium lock icon
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over
every (contiguous) subarray of arr. Since the answer may be large, return the
answer modulo 109 + 7.



Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
[3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17. Example 2:

Input: arr = [11,81,94,43,3]
Output: 444


Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // METHOD 1 gives TLE
  // int sumSubarrayMins(vector<int> &arr) {
  //   long long sum = 0;
  //   const int MOD = 1e9 + 7;
  //   int len = arr.size();
  //   for (int i = 0; i < arr.size(); i++) {
  //     int currMin = arr[i];
  //     for (int j = i; j < arr.size(); j++) {
  //       currMin = min(currMin, arr[j]);
  //       sum = (sum + currMin) % MOD;
  //     }
  //   }
  //   return int(sum);
  // }

  // METHOD 2
  int sumSubarrayMins(vector<int> &arr) {
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);
    int n = arr.size();
    int mod = 1e9 + 7;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int left = i - psee[i];
      int right = nse[i] - i;
      long long freq = left * right * 1LL;
      int val = (freq * arr[i] * 1LL) % mod;
      sum = (sum + val) % mod;
    }
    return sum;
  }

private:
  vector<int> findNSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      int currEle = arr[i];
      while (!st.empty() && arr[st.top()] >= arr[i]) {
        st.pop();
      }
      ans[i] = !st.empty() ? st.top() : n;
      st.push(i);
    }
    return ans;
  }

  vector<int> findPSEE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      int currEle = arr[i];
      while (!st.empty() && arr[st.top()] > arr[i]) {
        st.pop();
      }
      ans[i] = !st.empty() ? st.top() : -1;
      st.push(i);
    }
    return ans;
  }
};
