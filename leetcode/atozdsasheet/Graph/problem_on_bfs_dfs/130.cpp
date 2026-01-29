// 130. Surrounded Regions
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n matrix board containing letters 'X' and 'O', capture
// regions that are surrounded:
//
// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the
// region with 'X' cells and none of the region cells are on the edge of the
// board. To capture a surrounded region, replace all 'O's with 'X's in-place
// within the original board. You do not need to return anything.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int m, n;
  void dfs(int row, int col, vector<vector<char>> &board) {
    if (row < 0 || row >= m || col < 0 || col >= n)
      return;
    if (board[row][col] == 'O') {
      board[row][col] = '$';
      dfs(row - 1, col, board);
      dfs(row + 1, col, board);
      dfs(row, col + 1, board);
      dfs(row, col - 1, board);
    }
  }

public:
  void solve(vector<vector<char>> &board) {
    m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
      // first col
      if (board[i][0] == 'O') {
        dfs(i, 0, board);
      }
      // last col
      if (board[i][n - 1] == 'O') {
        dfs(i, n - 1, board);
      }
    }
    for (int i = 0; i < n; i++) {
      // first row
      if (board[0][i] == 'O') {
        dfs(0, i, board);
      }
      // last row
      if (board[m - 1][i] == 'O') {
        dfs(m - 1, i, board);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        if (board[i][j] == '$')
          board[i][j] = 'O';
        else
          board[i][j] = 'X';
    }
  }
};
