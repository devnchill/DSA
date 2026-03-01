// 1091. Shortest Path in Binary Matrix
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an n x n binary matrix grid, return the length of the shortest clear
// path in the matrix. If there is no clear path, return -1.
//
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0,
// 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//
// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they
// are different and they share an edge or a corner). The length of a clear path
// is the number of visited cells of this path.
//
//
//
// Example 1:
//
//
// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:
//
//
// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:
//
// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1
//
//
// Constraints:
//
// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid.empty())
      return -1;
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
      return -1;
    int dist = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> visited(m, vector<int>(n, 0));
    visited[0][0] = 1;
    while (!q.empty()) {
      dist++;
      int q_size = q.size();
      for (int i = 0; i < q_size; i++) {
        auto [a, b] = q.front();
        q.pop();
        if (a == m - 1 && b == n - 1)
          return dist;
        for (int j = 0; j < 8; j++) {
          int row = a + dx[j], col = b + dy[j];
          if (row >= 0 && row < m && col >= 0 && col < n &&
              grid[row][col] == 0 && !visited[row][col]) {
            visited[row][col] = 1;
            q.push({row, col});
          }
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  cout << s.shortestPathBinaryMatrix(grid);
}
