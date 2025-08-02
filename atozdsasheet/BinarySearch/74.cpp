/*
74. Search a 2D Matrix
Medium
Topics
premium lock iconCompanies

You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the
previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false



Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104
*/
#include <vector>
using std::vector;
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int osize = matrix.size();
    int olow = 0;
    int ohigh = osize - 1;
    int omid;
    while (olow <= ohigh) {
      omid = (olow + ohigh) / 2;
      vector<int> mid_vector = matrix[omid];
      int mid_vector_size = mid_vector.size();
      if (target >= mid_vector[0] &&
          target <= mid_vector[mid_vector_size - 1]) {
        int ilow = 0;
        int ihigh = mid_vector_size - 1;
        int imid;
        while (ilow <= ihigh) {
          imid = (ilow + ihigh) / 2;
          if (mid_vector[imid] == target)
            return true;
          if (mid_vector[imid] > target) {
            ihigh = imid - 1;
          } else {
            ilow = imid + 1;
          }
        }
        return false;
      } else if (target < mid_vector[0]) {
        ohigh = omid - 1;
      } else {
        olow = omid + 1;
      }
    }
    return false;
  }
};
#include <iostream>

int main() {
  Solution s;
  vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  std::cout << s.searchMatrix(nums, 13);
  return 0;
}
