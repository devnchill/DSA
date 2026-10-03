// 1727. Largest Submatrix With Rearrangements
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a binary matrix matrix of size m x n, and you are allowed to
// rearrange the columns of the matrix in any order.
//
// Return the area of the largest submatrix within matrix where every element of
// the submatrix is 1 after reordering the columns optimally.
//
//
//
// Example 1:
//
//
// Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
// Output: 4
// Explanation: You can rearrange the columns as shown above.
// The largest submatrix of 1s, in bold, has an area of 4.
// Example 2:
//
//
// Input: matrix = [[1,0,1,0,1]]
// Output: 3
// Explanation: You can rearrange the columns as shown above.
// The largest submatrix of 1s, in bold, has an area of 3.
// Example 3:
//
// Input: matrix = [[1,1,0],[1,0,1]]
// Output: 2
// Explanation: Notice that you must rearrange entire columns, and there is no
// way to make a submatrix of 1s larger than an area of 2.
//
//
// Constraints:
//
// m == matrix.length
// n == matrix[i].length
// 1 <= m * n <= 105
// matrix[i][j] is either 0 or 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestSubmatrix(vector<vector<int>> &matrix) {
    vector<vector<int>> ones(matrix.size(), vector<int>(matrix[0].size()));
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        ones[i][j] = matrix[i][j] == 0
                         ? 0
                         : (i == 0 ? matrix[i][j] : ones[i - 1][j] + 1);
      }
    }
    int max_area = 0;
    for (int i = 0; i < matrix.size(); i++) {
      sort(ones[i].begin(), ones[i].end(), greater<int>());
      for (int j = 0; j < matrix[0].size(); j++) {
        int area = (j + 1) * ones[i][j];
        max_area = max(area, max_area);
      }
    }
    return max_area;
  }
};
