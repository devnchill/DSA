// 994. Rotting Oranges Medium Topics premium lock icon Companies You are given
// an
//     m x n grid where each cell can have one of three values :
//
//     0 representing an empty cell,
//     1 representing a fresh orange,
//     or 2 representing a rotten orange.Every minute,
//     any fresh orange that is 4 -
//         directionally adjacent to a rotten orange becomes rotten
//             .
//
//         Return the minimum number of minutes that must elapse until no cell
//         has
//             a fresh orange.If this is impossible,
//     return -1.
//
//            Example 1 :
//
//     Input : grid =
//                [ [ 2, 1, 1 ], [ 1, 1, 0 ], [ 0, 1, 1 ] ] Output : 4 Example 2
//                :
//
//     Input : grid = [ [ 2, 1, 1 ], [ 0, 1, 1 ], [ 1, 0, 1 ] ] Output
//     : -1 Explanation : The orange in the bottom left
//                        corner(row 2, column 0) is never rotten,
//             because rotting only happens 4 - directionally.Example 3 :
//
//     Input : grid = [[ 0, 2 ]] Output : 0 Explanation
//     : Since there are already no fresh oranges at minute 0,
//             the answer is just 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, -1, +1};
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    int res = 0;
    int fresh = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
          visited[i][j] = true;
        } else if (grid[i][j] == 1)
          fresh++;
      }
    }
    while (!q.empty()) {
      int q_size = q.size();
      int fresh_state = fresh;
      for (int k = 0; k < q_size; k++) {
        auto [qr, qc] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nr = qr + dr[i];
          int nc = qc + dc[i];
          if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 1 ||
              visited[nr][nc])
            continue;
          q.push({nr, nc});
          fresh--;
          visited[nr][nc] = true;
        }
      }
      if (fresh != fresh_state)
        res++;
    }
    return fresh > 0 ? -1 : res;
  }
};
