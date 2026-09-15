// Problem Description: Given an array of n integers arr, return the Longest
// Increasing Subsequence (LIS) that is index-wise lexicographically smallest.
//
// The Longest Increasing Subsequence (LIS) is the longest subsequence where all
// elements are in strictly increasing order. A subsequence A1 is index-wise
// lexicographically smaller than another subsequence A2 if, at the first
// position where A1 and A2 differ, the element in A1 appears earlier in the
// array than corresponding element in A2.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> print_longest_lis(vector<int> &arr) {
    int n = arr.size();
    vector<int> prev(n, -1);
    vector<int> dp(n, 1);
    int lis_end = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
      if (dp[i] > dp[lis_end]) {
        lis_end = i;
      }
    }
    cout << "length of longest increasing subsequence is " << dp[lis_end]
         << "\n";
    vector<int> res;
    int pointer = lis_end;
    while (pointer != -1) {
      res.push_back(arr[pointer]);
      pointer = prev[pointer];
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
  auto res = s.print_longest_lis(arr);
  for (int &val : res)
    cout << val << " ";
}
