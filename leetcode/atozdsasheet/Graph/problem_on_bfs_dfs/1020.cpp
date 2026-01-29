// 1020. Number of Enclaves
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an m x n binary matrix grid, where 0 represents a sea cell and
// 1 represents a land cell.
//
// A move consists of walking from one land cell to another adjacent
// (4-directionally) land cell or walking off the boundary of the grid.
//
// Return the number of land cells in grid for which we cannot walk off the
// boundary of the grid in any number of moves.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> dr = {-1, 1, 0, 0};
  vector<int> dc = {0, 0, -1, 1};
  void dfs(vector<vector<int>> &grid, int m, int n, int row, int col) {
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 1)
      return;
    grid[row][col] = -1;
    for (int i = 0; i < 4; i++) {
      dfs(grid, m, n, row + dr[i], col + dc[i]);
    }
  }

public:
  int numEnclaves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < n; i++) {
      // first row
      if (grid[0][i] == 1)
        dfs(grid, m, n, 0, i);
      // last row
      if (grid[m - 1][i] == 1)
        dfs(grid, m, n, m - 1, i);
    }
    for (int i = 0; i < m; i++) {
      // first col
      if (grid[i][0] == 1)
        dfs(grid, m, n, i, 0);
      if (grid[i][n - 1] == 1)
        dfs(grid, m, n, i, n - 1);
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1)
          res += 1;
      }
    }
    return res;
  }
};
