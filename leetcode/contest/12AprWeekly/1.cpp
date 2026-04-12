#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findDegrees(vector<vector<int>> &matrix) {
    vector<int> res(matrix.size());
    vector<vector<int>> visited(matrix.size(),
                                vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 1 && !visited[i][j] && !visited[j][j]) {
          visited[i][j] = 1;
          visited[j][i] = 1;
          res[i]++, res[j]++;
        }
      }
    }
    return res;
  }
};
