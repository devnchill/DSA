// Topics
// premium lock icon
// Companies
// Hint
// You are given an m x n binary matrix grid and an integer health.
//
// You start on the upper-left corner (0, 0) and would like to get to the
// lower-right corner (m - 1, n - 1).
//
// You can move up, down, left, or right from one cell to another adjacent cell
// as long as your health remains positive.
//
// Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health
// by 1.
//
// Return true if you can reach the final cell with a health value of 1 or more,
// and false otherwise.
//
//
//
// Example 1:
//
// Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
//
// Output: true
//
// Explanation:
//
// The final cell can be reached safely by walking along the gray cells below.
//
//
// Example 2:
//
// Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]],
// health = 3
//
// Output: false
//
// Explanation:
//
// A minimum of 4 health points is needed to reach the final cell safely.
//
//
// Example 3:
//
// Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5
//
// Output: true
//
// Explanation:
//
// The final cell can be reached safely by walking along the gray cells below.
//
//
//
// Any path that does not go through the cell (1, 1) is unsafe since your health
// will drop to 0 when reaching the final cell.
//
//
//
// Constraints:
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// 2 <= m * n
// 1 <= health <= m + n
// grid[i][j] is either 0 or 1.

#include <bits/stdc++.h>
using namespace std;

// Bruteforce
class Solution {
private:
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  vector<vector<bool>> visited;
  bool is_valid(int i, int j, vector<vector<int>> &grid) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
      return false;
    return true;
  }
  bool recurse(int i, int j, vector<vector<int>> &grid, int health) {
    if (visited[i][j])
      return false;
    if (health < 1)
      return false;
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
      return true;
    visited[i][j] = true;
    bool res = false;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k], y = j + dy[k];
      if (!is_valid(x, y, grid))
        continue;
      res |= recurse(x, y, grid, health - grid[x][y]);
      if (res)
        return true;
    }
    visited[i][j] = false;
    return res;
  }

public:
  bool findSafeWalk(vector<vector<int>> &grid, int health) {
    visited.assign(grid.size(), vector<bool>(grid[0].size(), false));
    return recurse(0, 0, grid, health - grid[0][0]);
  }
};

// Approach 2
class Solution2 {
private:
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  vector<vector<bool>> visited;
  vector<vector<vector<int>>> dp;

  bool is_valid(int i, int j, vector<vector<int>> &grid) {
    return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
  }

  bool dfs(int i, int j, vector<vector<int>> &grid, int health) {
    if (health < 1)
      return false;
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
      return true;
    if (dp[i][j][health] != -1)
      return dp[i][j][health];
    visited[i][j] = true;
    bool ans = false;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (!is_valid(x, y, grid))
        continue;
      if (visited[x][y])
        continue;
      ans |= dfs(x, y, grid, health - grid[x][y]);
      if (ans)
        break;
    }
    visited[i][j] = false;
    return dp[i][j][health] = ans;
  }

public:
  bool findSafeWalk(vector<vector<int>> &grid, int health) {
    int n = grid.size();
    int m = grid[0].size();
    health -= grid[0][0];

    if (health < 1)
      return false;

    visited.assign(n, vector<bool>(m, false));
    dp.assign(n, vector<vector<int>>(m, vector<int>(health + 1, -1)));

    return dfs(0, 0, grid, health);
  }
};
