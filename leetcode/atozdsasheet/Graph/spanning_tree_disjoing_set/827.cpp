// 827. Making A Large Island
// Hard
// Topics
// premium lock icon
// Companies
// You are given an n x n binary matrix grid. You are allowed to change at most
// one 0 to be 1.
//
// Return the size of the largest island in grid after applying this operation.
//
// An island is a 4-directionally connected group of 1s.
//
// Example 1:
//
// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with
// area = 3. Example 2:
//
// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island
// with area = 4. Example 3:
//
// Input: grid = [[1,1],[1,1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.
//
//
// Constraints:
//
// n == grid.length
// n == grid[i].length
// 1 <= n <= 500
// grid[i][j] is either 0 or 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> dr = {-1, 0, 1, 0};
  vector<int> dc = {0, 1, 0, -1};
  int dfs(int i, int j, vector<vector<int>> &grid, int id) {
    int n = grid.size();
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
      return 0;
    grid[i][j] = id;
    int area = 1;
    for (int d = 0; d < 4; d++) {
      area += dfs(i + dr[d], j + dc[d], grid, id);
    }
    return area;
  }

public:
  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    unordered_map<int, int> area;
    int id = 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          area[id] = dfs(i, j, grid, id);
          id++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          unordered_set<int> seen;
          int curr = 1;
          for (int d = 0; d < 4; d++) {
            int ni = i + dr[d];
            int nj = j + dc[d];
            if (ni >= 0 && nj >= 0 && ni < n && nj < n) {
              int nid = grid[ni][nj];
              if (nid > 1 && !seen.count(nid)) {
                curr += area[nid];
                seen.insert(nid);
              }
            }
          }
          ans = max(ans, curr);
        }
      }
    }
    if (ans == 0)
      return n * n;
    return ans;
  }
};
