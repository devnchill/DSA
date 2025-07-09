// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <iostream>
#include <vector>
class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    std::vector<int> output;
    while (top <= bottom && left <= right) {
      // top boundary
      for (int j = left; j <= right; j++) {
        output.push_back(matrix[top][j]);
      }
      top++;
      // right boundary
      for (int i = top; i <= bottom; i++) {
        output.push_back(matrix[i][right]);
      }
      right--;
      // bottom boundary
      if (top <= bottom) {
        for (int j = right; j >= left; j--) {
          output.push_back(matrix[bottom][j]);
        }
        bottom--;
      }
      // left boundary
      if (left <= right) {
        for (int i = bottom; i >= top; i--) {
          output.push_back(matrix[i][left]);
        }
        left++;
      }
    }
    return output;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<int> result = sol.spiralOrder(matrix);
  for (int num : result) {
    std::cout << num << " ";
  }
}
