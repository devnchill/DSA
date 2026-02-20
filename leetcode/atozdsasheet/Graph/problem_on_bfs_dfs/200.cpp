// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and
// '0's (water), return the number of islands.
//
// An island is surrounded by water and is formed by connecting adjacent lands
// horizontally or vertically. You may assume all four edges of the grid are all
// surrounded by water.
//
//
//
// Example 1:
//
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:
//
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
//
//
// Constraints:
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  vector<vector<bool>> visited_coords;
  int max_i, max_j;
  void dfs(int i, int j, vector<vector<char>> &grid) {
    if (i < 0 || i > max_i || j < 0 || j > max_j || grid[i][j] == '0')
      return;
    if (visited_coords[i][j])
      return;
    visited_coords[i][j] = true;
    for (int k = 0; k < 4; k++) {
      dfs(i + dx[k], j + dy[k], grid);
    }
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty())
      return 0;
    int res = 0;
    max_i = grid.size() - 1;
    max_j = grid[0].size() - 1;
    visited_coords.assign(max_i + 1, vector<bool>(max_j + 1, false));
    for (int i = 0; i <= max_i; i++) {
      for (int j = 0; j <= max_j; j++) {
        if (grid[i][j] == '1' && !visited_coords[i][j]) {
          res++;
          // cout << "increamenting res for i= " << i << " j= " << j << "\n";
          dfs(i, j, grid);
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
  cout << s.numIslands(grid);
}
