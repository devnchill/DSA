/*
76. Minimum Window Substring
Hard
Topics
premium lock icon
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string
"".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from
string t. Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // METHOD 1 BRUTEFORCE
  // string minWindow(string s, string t) {
  //   int n = s.size();
  //   int t_size = t.size();
  //   bool found = false;
  //   string min_res = "";
  //   unordered_map<char, int> m;
  //   for (char ch : t)
  //     m[ch]++;
  //   for (int i = 0; i < n; i++) {
  //     string substring;
  //     for (int j = i; j < n; j++) {
  //       substring.push_back(s[j]);
  //       if (j - i + 1 >= t_size) {
  //         unordered_map<char, int> temp = m;
  //         for (char ch : substring)
  //           temp[ch]--;
  //         bool isqualified = true;
  //         for (auto &v : temp) {
  //           if (v.second > 0) {
  //             isqualified = false;
  //             break;
  //           }
  //         }
  //         if ((isqualified) && (substring.size() < min_res.size() || !found))
  //         {
  //           min_res = substring;
  //           found = true;
  //         }
  //       }
  //     }
  //   }
  //   return found ? min_res : "";
  // }

  // METHOD 2
  string minWindow(string s, string t) {
    if (t.size() > s.size())
      return "";
    bool found = false;
    unordered_map<char, int> freq;
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int len_s = s.size(), len_t = t.size();
    int res_left = 0, res_right = 0;
    for (char ch : t)
      freq[ch]++;
    int formed = 0;
    for (right = 0; right < len_s; right++) {
      char curr_char = s[right];
      window[curr_char]++;
      if (freq.find(curr_char) != freq.end() &&
          freq[curr_char] == window[curr_char])
        formed++;
      if (formed == freq.size()) {
        while (formed >= freq.size()) {
          if (right - left + 1 < res_right - res_left + 1 || !found) {
            found = true;
            res_right = right;
            res_left = left;
          }
          window[s[left]]--;
          if (freq.count(s[left]) && window[s[left]] < freq[s[left]])
            formed--;
          left++;
        }
      }
    }
    return found ? s.substr(res_left, res_right - res_left + 1) : "";
  }
};

int main() {
  Solution s;
  cout << s.minWindow("casabb", "caa") << "\n";
  return 0;
}
