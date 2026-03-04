// 1631. Path With Minimum Effort
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D
// array of size rows x columns, where heights[row][col] represents the height
// of cell (row, col). You are situated in the top-left cell, (0, 0), and you
// hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e.,
// 0-indexed). You can move up, down, left, or right, and you wish to find a
// route that requires the minimum effort.
//
// A route's effort is the maximum absolute difference in heights between two
// consecutive cells of the route.
//
// Return the minimum effort required to travel from the top-left cell to the
// bottom-right cell.
//
//
//
// Example 1:
//
//
//
// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2
// in consecutive cells. This is better than the route of [1,2,2,2,5], where the
// maximum absolute difference is 3. Example 2:
//
//
//
// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1
// in consecutive cells, which is better than route [1,3,5,3,5]. Example 3:
//
//
// Input: heights =
// [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]] Output: 0
// Explanation: This route does not require any effort.
//
//
// Constraints:
//
// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106

#include <bits/stdc++.h>
class Solution {
public:
  int minimumEffortPath(std::vector<std::vector<int>> &heights) {
    if (heights.empty()) {
      return 0;
    }

    int rows = heights.size();
    int cols = heights[0].size();
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        std::greater<std::vector<int>>>
        minHeap; // {effort, row, col}
    minHeap.push({0, 0, 0});
    int maxEffort = 0;
    std::set<std::string> visited;

    while (!minHeap.empty()) {
      auto current = minHeap.top();
      minHeap.pop();
      int effort = current[0];
      int curRow = current[1];
      int curCol = current[2];

      maxEffort = std::max(maxEffort, effort);
      if (curRow == rows - 1 && curCol == cols - 1) {
        return maxEffort;
      }
      visited.insert(std::to_string(curRow) + "," + std::to_string(curCol));

      std::vector<std::vector<int>> directions = {
          {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      for (const auto &direction : directions) {
        int newRow = curRow + direction[0];
        int newCol = curCol + direction[1];

        if (0 <= newRow && newRow < rows && 0 <= newCol && newCol < cols &&
            visited.find(std::to_string(newRow) + "," +
                         std::to_string(newCol)) == visited.end()) {
          int newEffort =
              std::abs(heights[newRow][newCol] - heights[curRow][curCol]);
          minHeap.push({newEffort, newRow, newCol});
        }
      }
    }

    return maxEffort;
  }
};
