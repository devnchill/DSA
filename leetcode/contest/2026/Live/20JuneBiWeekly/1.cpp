#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> createGrid(int m, int n) {
    vector<string> grid;
    for (int i = 0; i < m; i++) {
      string row;
      for (int j = 0; j < n; j++) {
        if (i == 0)
          row.push_back('.');
        else {
          if (j == n - 1)
            row.push_back('.');
          else
            row.push_back('#');
        }
      }
      grid.push_back(row);
    }
    return grid;
  }
};

int main() {
  Solution s;
  auto res = s.createGrid(1, 4);
  for (string &row : res)
    cout << row << "\n";
}
