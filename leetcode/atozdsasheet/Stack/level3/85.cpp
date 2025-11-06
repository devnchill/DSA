/*
85. Maximal Rectangle
Hard
Topics
premium lock icon
Companies
Given a rows x cols binary matrix filled with 0's and 1's, find the largest
rectangle containing only 1's and return its area.

Example 1:

Input: matrix =
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1


Constraints:

rows == matrix.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int max_rectangle_area = 0;
    vector<int> height(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == '1')
          height[j]++;
        else
          height[j] = 0;
      }
      max_rectangle_area =
          max(max_rectangle_area, largestRectangleArea(height));
    }
    return max_rectangle_area;
  }

private:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> st;
    int max_area = 0;

    for (int i = 0; i <= n; i++) {
      int h = (i == n ? 0 : heights[i]);
      while (!st.empty() && h < heights[st.top()]) {
        int height = heights[st.top()];
        st.pop();
        int width = st.empty() ? i : (i - st.top() - 1);
        max_area = max(max_area, height * width);
      }
      st.push(i);
    }
    return max_area;
  }
};
