/*
* 242. Valid Anagram
Easy
Topics
premium lock iconCompanies

Given two strings s and t, return true if t is an

of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

*/
#include <iostream>
#include <map>
#include <string>
using std::map;
using std::string;
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    map<char, int> m;
    for (auto ch : s) {
      m[ch]++;
    }
    for (auto c : t) {
      m[c]--;
      if (m[c] < 0)
        return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.isAnagram("anagram", "nagaram") << std::endl;
  std::cout << s.isAnagram("rat", "car");
  return 0;
}
