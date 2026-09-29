// A parentheses string is a non-empty string consisting only of '(' and ')'. It
// is valid if any of the following conditions is true:
//
// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid
// parentheses strings. It can be written as (A), where A is a valid parentheses
// string. You are given an m x n matrix of parentheses grid. A valid
// parentheses string path in the grid is a path satisfying all of the following
// conditions:
//
// The path starts from the upper left cell (0, 0).
// The path ends at the bottom-right cell (m - 1, n - 1).
// The path only ever moves down or right.
// The resulting parentheses string formed by the path is valid.
// Return true if there exists a valid parentheses string path in the grid.
// Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<vector<int>>> dp;
  bool rec(int i, int j, int curr, vector<vector<char>> &path) {

    if (i < 0 || i >= path.size() || j < 0 || j >= path[0].size()) {
      return false;
    }

    if (path[i][j] == '(') {
      curr++;
    } else if (path[i][j] == (')')) {
      curr--;
    }
    if (curr < 0)
      return false;
    if (dp[i][j][curr] != -1)
      return dp[i][j][curr];

    if (i == path.size() - 1 && j == path[0].size() - 1) {
      return dp[i][j][curr] = curr == 0 ? true : false;
    }

    return dp[i][j][curr] =
               rec(i + 1, j, curr, path) || rec(i, j + 1, curr, path);
  }

public:
  bool hasValidPath(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    dp.assign(n, vector<vector<int>>(m, vector<int>(n + m + 1, -1)));
    return (rec(0, 0, 0, grid));
  }
};
