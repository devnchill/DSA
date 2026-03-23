// 3212. Count Submatrices With Equal Frequency of X and Y
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or
// '.', return the number of submatrices that contain:
//
// grid[0][0]
// an equal frequency of 'X' and 'Y'.
// at least one 'X'.
//
//
// Example 1:
//
// Input: grid = [["X","Y","."],["Y",".","."]]
//
// Output: 3
//
// Explanation:
//
//
//
// Example 2:
//
// Input: grid = [["X","X"],["X","Y"]]
//
// Output: 0
//
// Explanation:
//
// No submatrix has an equal frequency of 'X' and 'Y'.
//
// Example 3:
//
// Input: grid = [[".","."],[".","."]]
//
// Output: 0
//
// Explanation:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<int> sumX(cols, 0);
    vector<int> sumY(cols, 0);
    int res = 0;

    for (int i = 0; i < rows; i++) {
      int rx = 0, ry = 0;

      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 'X')
          rx++;
        else if (grid[i][j] == 'Y')
          ry++;
        sumX[j] += rx;
        sumY[j] += ry;
        if (sumX[j] > 0 && sumX[j] == sumY[j])
          res++;
      }
    }
    return res;
  }
};
