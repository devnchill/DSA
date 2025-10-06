/*
304. Range Sum Query 2D - Immutable
Medium
Topics
premium lock iconCompanies

Given a 2D matrix matrix, handle multiple queries of the following type:

    Calculate the sum of the elements of matrix inside the rectangle defined by
its upper left corner (row1, col1) and lower right corner (row2, col2).

Implement the NumMatrix class:

    NumMatrix(int[][] matrix) Initializes the object with the integer matrix
matrix. int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of
the elements of matrix inside the rectangle defined by its upper left corner
(row1, col1) and lower right corner (row2, col2).

You must design an algorithm where sumRegion works on O(1) time complexity.
*/
#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
  vector<vector<int>> prefix;
  NumMatrix(vector<vector<int>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    prefix.assign(rows + 1, vector<int>(cols + 1, 0));

    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j++) {
        prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] +
                       prefix[i][j - 1] - prefix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    row1++, col1++, row2++, col2++;
    return prefix[row2][col2] - prefix[row1 - 1][col2] -
           prefix[row2][col1 - 1] + prefix[row1 - 1][col1 - 1];
  }
};
