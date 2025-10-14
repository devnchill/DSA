/*
* 451. Sort Characters By Frequency
Medium
Topics
premium lock iconCompanies

Given a string s, sort it in decreasing order based on the frequency of the
characters. The frequency of a character is the number of times it appears in
the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
answer.

Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc"
are valid answers. Note that "cacaca" is incorrect, as the same characters must
be together.

Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;
class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s)
      freq[c]++;
    vector<pair<char, int>> v(freq.begin(), freq.end());
    sort(v.begin(), v.end(),
         [](auto &a, auto &b) { return a.second > b.second; });

    string res;
    res.reserve(s.size());
    for (auto &[ch, count] : v)
      res.append(count, ch);

    return res;
  }
};
