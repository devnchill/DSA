#include <bits/stdc++.h>
using namespace std;

// This method gives TLE
class Solution {
public:
  int countLocalMaximums(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size(), res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = matrix[i][j];
        if (x == 0)
          continue;
        bool ok = true;
        for (int r = max(0, i - x); r <= min(i + x, n - 1); r++) {
          for (int c = max(0, j - x); c <= min(j + x, m - 1); c++) {
            if (abs(r - i) == x && abs(c - j) == x)
              continue;
            if (matrix[r][c] > x) {
              ok = false;
              break;
            }
          }
          if (!ok)
            break;
        }
        if (ok)
          res++;
      }
    }
    return res;
  }
};
