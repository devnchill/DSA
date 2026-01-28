// Given an m x n binary matrix mat, return the distance of the nearest 0 for
// each cell.
//
// The distance between two cells sharing a common edge is 1.

#include <bits/stdc++.h>
#include <climits>
using namespace std;

// METHOD 1 BFS For every 0
// GIVES TLE
class Solution1 {
private:
  vector<int> dr = {1, -1, 0, 0};
  vector<int> dc = {0, 0, -1, 1};
  vector<vector<int>> mat;

  void bfs(int m, int n, int row, int col) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    q.push({row, col});
    visited[row][col] = true;

    int dist = 0;

    while (!q.empty()) {
      int sz = q.size();

      while (sz--) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i];
          int nc = c + dc[i];

          if (nr < 0 || nr >= m || nc < 0 || nc >= n)
            continue;
          if (visited[nr][nc])
            continue;
          if (mat[nr][nc] <= dist + 1)
            continue;

          visited[nr][nc] = true;
          mat[nr][nc] = dist + 1;
          q.push({nr, nc});
        }
      }
      dist++;
    }
  }

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &input) {
    int m = input.size(), n = input[0].size();
    mat = input;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (input[i][j] == 0) {
          q.push({i, j});
        } else {
          input[i][j] = INT_MAX;
        }
      }
    }

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      bfs(m, n, r, c);
    }

    return input;
  }
};
;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    const int INF = 1e9;
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> res(m, vector<int>(n, INF));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0)
          res[i][j] = 0;
        else {
          if (i > 0)
            res[i][j] = min(res[i][j], res[i - 1][j] + 1);
          if (j > 0)
            res[i][j] = min(res[i][j], res[i][j - 1] + 1);
        }
      }
    }
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (mat[i][j] != 0) {
          if (i < m - 1)
            res[i][j] = min(res[i][j], res[i + 1][j] + 1);
          if (j < n - 1)
            res[i][j] = min(res[i][j], res[i][j + 1] + 1);
        }
      }
    }
    return res;
  }
};
