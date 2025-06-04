/*Given an m x n integer matrix matrix, if an element is 0, set its entire row
and column to 0's.

You must do it in place.

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1
*/

#include <iostream>
#include <vector>
using std::pair;
using std::vector;
class Solution {
public:
  // Method 1 . Bruteforce. Uses extra space depending on no of coordinates .
  // Mark first , modify later approach.
  void setZeroes(vector<vector<int>> &matrix) {
    // create a vector of pairs.
    vector<pair<int, int>> coor;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if ((matrix[i][j]) == 0) {
          coor.push_back(std::make_pair(i, j));
        }
      }
    }
    for (auto it : coor) {
      int x = it.first;
      int y = it.second;
      for (int i = 0; i < m; i++) {
        matrix[i][y] = 0;
      }
      for (int j = 0; j < n; j++) {
        matrix[x][j] = 0;
      }
      for (const auto &row : matrix) {
        for (const auto &elem : row) {
          std::cout << elem << " ";
        }
        std::cout << std::endl;
      }
    }
  }

  // Method 2.

  void setZeroes2(vector<vector<int>> &matrix) {
    bool row0 = false, col0 = false;
    int m = matrix.size();
    int n = matrix[0].size();
    // check if 1st row and 1st col are already 0 or no before marking
    for (int j = 0; j < n; j++) {
      if (matrix[0][j] == 0)
        row0 = true;
    }
    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0)
        col0 = true;
    }
    // mark first row and first col for that row and col as 0 if element is
    // already 0.
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    // mark all elements of that row and col as 0 if first row or col for that
    // is 0
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    // mark all element of first row and col as 0 if row0 and col0 are true.
    if (row0) {
      for (int j = 0; j < n; j++)
        matrix[0][j] = 0;
    }
    if (col0) {
      for (int i = 0; i < m; i++)
        matrix[i][0] = 0;
    }
  };
};

int main(int argc, char *argv[]) {
  vector<vector<int>> nums = {
      {1, 10, 2, 8, 37},
      {1, 4, 21, 0, 18},
      {31, 4, 22, 59, 10},
  };
  Solution s;
  s.setZeroes2(nums);
  for (auto row : nums) {
    for (auto element : row) {
      std::cout << element << ",";
    }
    std::cout << std::endl;
  }
  return 0;
}
