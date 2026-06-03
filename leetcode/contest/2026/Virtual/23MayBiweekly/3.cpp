// Q3. Maximum Path Intersection Sum in a Grid
// Medium
// 5 pt.
// You are given an m x n integer matrix grid.
//
// Two players move across the grid:
//
// Player 1 starts at the top-left cell (0, 0) and can move only right or down.
// Their destination is the bottom-right cell (m - 1, n - 1). Player 2 starts at
// the bottom-left cell (m - 1, 0) and can move only right or up. Their
// destination is the top-right cell (0, n - 1). Each player must choose a valid
// path from their respective starting cell to their destination.
//
// A cell is called shared if it belongs to both chosen paths.
//
// Return an integer denoting the maximum possible sum of values of all shared
// cells.
//
//
//
// Example 1:
//
// ​​​​​​​​​​​​​​​​​​​​​
// Input: grid = [[1,2,0,-3],[1,-2,1,0],[-4,2,-1,3],[3,-3,3,-2],[-1,-5,0,1]]
//
// Output: 4
//
// Explanation:
//
// The diagram shows one optimal choice of paths.
// Player 1 follows the red/purple path from the top-left cell to the
// bottom-right cell: (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2) → (2, 3) → (3,
// 3) → (4, 3) Player 2 follows the blue/purple path from the bottom-left cell
// to the top-right cell: (4, 0) → (4, 1) → (3, 1) → (2, 1) → (2, 2) → (2, 3) →
// (1, 3) → (0, 3) The shared cells are (2, 1), (2, 2), and (2, 3). The sum is 2
// + (-1) + 3 = 4, which is the maximum possible sum. Example 2:
//
//
// Input: grid = [[4,-2,-3],[-1,-3,-1],[-4,2,-1]]
//
// Output: 3
//
// Explanation:
//
// One optimal pair of paths is shown in the diagram.
//
// Player 1 follows the red/purple path:
// (0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2)
// Player 2 follows the blue/purple path:
// (2, 0) → (1, 0) → (0, 0) → (0, 1) → (0, 2)
// The shared cells are (0, 0) and (1, 0).
// The sum is 4 + (-1) = 3, which is the maximum possible.
//
//
// Constraints:
//
// m == grid.length
// n == grid[i].length
// 2 <= m, n <= 1000
// 4 <= m * n <= 5 * 105
// -100 <= grid[i][j] <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxScore(vector<vector<int>> &grid) {
    int sum = INT_MIN;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      int curr = grid[i][0];
      for (int j = 1; j < n; j++) {
        int len2 = curr + grid[i][j];
        sum = max(sum, len2);
        if (i > 0 && i < m - 1 && j > 0 && j < n - 1)
          sum = max(sum, grid[i][j]);
        curr = max(grid[i][j], grid[i][j] + curr);
      }
    }
    for (int j = 0; j < n; j++) {
      int curr = grid[0][j];
      for (int i = 1; i < m; i++) {
        int len2 = curr + grid[i][j];
        sum = max(sum, len2);
        if (i > 0 && i < m - 1 && j > 0 && j < n - 1)
          sum = max(sum, grid[i][j]);
        curr = max(grid[i][j], grid[i][j] + curr);
      }
    }
    return sum;
  }
};
