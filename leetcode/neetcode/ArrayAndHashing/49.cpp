/*Given an array of strings strs, group the

together. You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form
each other. The strings "ate", "eat", and "tea" are anagrams as they can be
rearranged to form each other.

Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

*/
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;
    for (string st : strs) {
      string key = st;
      sort(key.begin(), key.end());
      m[key].push_back(st);
    }
    for (auto k : m) {
      res.push_back(k.second);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> nums = {"cat", "bat", "rat", "tac"};
  vector<vector<string>> res = s.groupAnagrams(nums);
  for (auto it : res) {
    for (auto jit : it) {
      cout << jit << " ";
    }
    cout << endl;
  }
  return 0;
}
