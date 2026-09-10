// Problem Statement: Given an integer array nums, return the length of the
// longest strictly increasing subsequence.
//
// A subsequence is a sequence derived from an array by deleting some or no
// elements without changing the order of the remaining elements. For example,
// [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].
//
// The task is to find the length of the longest subsequence in which every
// element is greater than the previous one.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
  int lis(vector<int> &nums) {
    vector<int> temp;
    for (int val : nums) {
      if (temp.empty() || val > temp.back())
        temp.push_back(val);
      else {
        int idx = lower_bound(temp.begin(), temp.end(), val) - temp.begin();
        temp[idx] = val;
      }
    }
    return temp.size();
  }
};
