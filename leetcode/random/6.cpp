/*
6. Zigzag Conversion
Medium
Topics
premium lock icon
Companies
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size())
      return s;
    int n = s.size();
    vector<vector<char>> res(numRows);
    int y = 0;
    bool rev = false;
    string zig_zag_string;
    for (char c : s) {
      res[y].push_back(c);
      if (y == numRows - 1)
        rev = true;
      else if (y == 0)
        rev = false;
      y += rev ? -1 : 1;
    }
    for (auto val : res) {
      for (char ch : val) {
        zig_zag_string.push_back(ch);
      }
    }
    return zig_zag_string;
  }
};
int main() {
  Solution s;
  s.convert("PAYPALISHIRING", 3);
  return 0;
}
