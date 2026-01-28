// You are given an image represented by an m x n grid of integers image, where
// image[i][j] represents the pixel value of the image. You are also given three
// integers sr, sc, and color. Your task is to perform a flood fill on the image
// starting from the pixel image[sr][sc].
//
// To perform a flood fill:
//
// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels
// that share a side with the original pixel, either horizontally or vertically)
// and shares the same color as the starting pixel. Keep repeating this process
// by checking neighboring pixels of the updated pixels and modifying their
// color if it matches the original color of the starting pixel. The process
// stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int m = image.size(), n = image[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    while (!q.empty()) {
      int q_size = q.size();
      for (int i = 0; i < q_size; i++) {
        auto [qr, qc] = q.front();
        visited[qr][qc] = true;
        q.pop();
        int val = image[qr][qc];
        image[qr][qc] = color;
        for (int j = 0; j < 4; j++) {
          int nr = qr + dr[j], nc = qc + dc[j];
          if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc])
            continue;
          if (image[nr][nc] == val) {
            cout << "changing value of row:" << nr << " col: " << nc << "\n";
            q.push({nr, nc});
          }
        }
      }
    }
    return image;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  s.floodFill(image, 1, 1, 2);
  return 0;
}
