/*
1578. Minimum Time to Make Rope Colorful
Medium
Topics
premium lock icon
Companies
Hint
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors
where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons
to be of the same color, so she asks Bob for help. Bob can remove some balloons
from the rope to make it colorful. You are given a 0-indexed integer array
neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove
the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

Example 1:

Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
Example 2:


Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any
balloons from the rope.

Example 3:

Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons
takes 1 second to remove. There are no longer two consecutive balloons of the
same color. Total time = 1 + 1 = 2.

Constraints:

n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCost(string colors, vector<int> &neededTime) {
    int res = 0;
    int n = colors.size();
    int first = 0;
    for (int second = 1; second < n; second++) {
      if (colors[first] == colors[second]) {
        res += min(neededTime[first], neededTime[second]);
        if (neededTime[second] > neededTime[first])
          first = second;
      } else {
        first = second;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  string colors = "bbbaaa ";
  vector<int> neededTime = {4, 9, 3, 8, 8, 9};
  cout << s.minCost(colors, neededTime);
  return 0;
}
