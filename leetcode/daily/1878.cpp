// 1878. Get Biggest Three Rhombus Sums in a Grid
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an m x n integer matrix grid​​​.
//
// A rhombus sum is the sum of the elements that form the border of a regular
// rhombus shape in grid​​​. The rhombus must have the shape of a square
// rotated 45 degrees with each of the corners centered in a grid cell. Below is
// an image of four valid rhombus shapes with the corresponding colored cells
// that should be included in each rhombus sum:
//
//
// Note that the rhombus can have an area of 0, which is depicted by the purple
// rhombus in the bottom right corner.
//
// Return the biggest three distinct rhombus sums in the grid in descending
// order. If there are less than three distinct values, return all of them.
//
//
//
// Example 1:
//
//
// Input: grid =
// [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]] Output:
// [228,216,211] Explanation: The rhombus shapes for the three biggest distinct
// rhombus sums are depicted above.
// - Blue: 20 + 3 + 200 + 5 = 228
// - Red: 200 + 2 + 10 + 4 = 216
// - Green: 5 + 200 + 4 + 2 = 211
// Example 2:
//
//
// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [20,9,8]
// Explanation: The rhombus shapes for the three biggest distinct rhombus sums
// are depicted above.
// - Blue: 4 + 2 + 6 + 8 = 20
// - Red: 9 (area 0 rhombus in the bottom right corner)
// - Green: 8 (area 0 rhombus in the bottom middle)
// Example 3:
//
// Input: grid = [[7,7,7]]
// Output: [7]
// Explanation: All three possible rhombus sums are the same, so return [7].
//
//
// Constraints:
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// 1 <= grid[i][j] <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int m, n;
  bool validate_coords(int i, int j, int k) {
    if (k == 0 && (i >= 0 && i < m && j >= 0 && j < n))
      return true;
    vector<pair<int, int>> coords = {
        {i, j}, {i + k, j - k}, {i + 2 * k, j}, {i + k, j + k}};
    for (auto &[a, b] : coords) {
      if (a < 0 || a >= m || b < 0 || b >= n)
        return false;
    }
    return true;
  }
  int get_sum_of_rhombus(vector<vector<int>> &grid, int i, int j, int k) {
    if (k == 0)
      return grid[i][j];
    int s = 0, a = i, b = j;
    // top to left
    for (int step = 0; step < k; step++) {
      a++;
      b--;
      s += grid[a][b];
    }
    // left to bottom
    for (int step = 0; step < k; step++) {
      a++;
      b++;
      s += grid[a][b];
    }
    // bottom to right
    for (int step = 0; step < k; step++) {
      a--;
      b++;
      s += grid[a][b];
    }
    // right to top
    for (int step = 0; step < k; step++) {
      a--;
      b--;
      s += grid[a][b];
    }
    return s;
  };

public:
  vector<int> getBiggestThree(vector<vector<int>> &grid) {
    set<int> sum;
    m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0;; k++) {
          if (!validate_coords(i, j, k)) {
            break;
          }
          sum.insert(get_sum_of_rhombus(grid, i, j, k));
        }
      }
    }
    vector<int> res;
    for (auto it = sum.rbegin(); it != sum.rend() && res.size() < 3; ++it) {
      res.push_back(*it);
    }
    return res;
  }
};
