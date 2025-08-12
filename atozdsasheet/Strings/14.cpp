/* Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string prefix = "";
    for (int i = 0; i < strs[0].size(); i++) {
      for (int word = 1; word < strs.size(); word++) {
        if (strs[0][i] != strs[word][i] || i >= strs[word].size()) {
          return prefix;
        }
      }
      prefix.push_back(strs[0][i]);
    }
    return prefix;
  }
};
