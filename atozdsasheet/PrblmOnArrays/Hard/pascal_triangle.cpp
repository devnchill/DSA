/*Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above
it as shown:
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

Constraints:
    1 <= numRows <= 30

*/
#include <vector>
using std::vector;
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    triangle.push_back({1});
    for (int i = 1; i < numRows; ++i) {
      const vector<int> &prev = triangle.back();
      vector<int> padded(prev.size() + 2, 0);
      for (int j = 0; j < prev.size(); ++j) {
        padded[j + 1] = prev[j];
      }
      vector<int> row;
      for (int j = 0; j < padded.size() - 1; ++j) {
        row.push_back(padded[j] + padded[j + 1]);
      }
      triangle.push_back(row);
    }
    return triangle;
  }
};
