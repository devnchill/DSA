/*
84. Largest Rectangle in Histogram
Hard
Topics
premium lock icon
Companies
Given an array of integers heights representing the histogram's bar height where
the width of each bar is 1, return the area of the largest rectangle in the
histogram.



Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4


Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int max_area = 0;
    int n = heights.size();
    vector<int> right(n, n);
    vector<int> left(n, -1);
    stack<int> right_smaller;
    stack<int> left_smaller;
    for (int i = n - 1; i >= 0; i--) {
      if (right_smaller.empty()) {
        right_smaller.push(i);
        continue;
      }
      while (!right_smaller.empty() &&
             heights[right_smaller.top()] > heights[i]) {
        right_smaller.pop();
      }
      right[i] = right_smaller.empty() ? n : right_smaller.top();
      right_smaller.push(i);
    }

    for (int i = 0; i < n; i++) {
      if (left_smaller.empty()) {
        left_smaller.push(i);
        continue;
      }
      while (!left_smaller.empty() &&
             heights[left_smaller.top()] >= heights[i]) {
        left_smaller.pop();
      }
      left[i] = left_smaller.empty() ? -1 : left_smaller.top();
      left_smaller.push(i);
    }
    for (int i = 0; i < n; i++) {
      int l_index = left[i];
      int r_index = right[i];
      max_area = max(max_area, heights[i] * (r_index - l_index - 1));
    }
    return max_area;
  }
};
