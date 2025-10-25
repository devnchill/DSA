/*
42. Trapping Rain Water
Hard
Topics
premium lock icon
Companies
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped. Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    size_t len = height.size();
    int sum = 0;
    vector<int> left_max(len, 0);
    vector<int> right_max(len, 0);
    for (int i = 0; i < static_cast<int>(len); i++) {
      if (i == 0)
        left_max[i] = 0;
      else
        left_max[i] = max(height[i - 1], left_max[i - 1]);
    }
    for (int i = len - 2; i >= 0; i--) {
      if (i == static_cast<int>(len) - 1)
        right_max[i] = 0;
      else
        right_max[i] = max(height[i + 1], right_max[i + 1]);
    }
    for (size_t i = 0; i < len; i++) {
      int left = left_max[i];
      int right = right_max[i];
      int trapped = (min(left, right)) - height[i];
      if (trapped < 0)
        continue;
      sum += trapped;
    }
    return sum;
  }
};

int main() {
  Solution s;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << s.trap(height);
  return 0;
}
