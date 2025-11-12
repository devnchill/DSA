/*
5. Longest Palindromic Substring
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool is_palindrome(string s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
  }

  vector<int> expand_and_check_palindrome(string &s, int first, int second,
                                          int n) {
    while (first >= 0 && second < n && s[first] == s[second]) {
      first--;
      second++;
    }
    return {first + 1, second - 1};
  }

public:
  // METHOD 1 BRUTEFORCE OFC TLE
  // generate all substring and check if its a substring if it is then compare
  // it with last stored substring of max len found till yet. if ifs length is
  // greater then keep this substring as max otherwise continue
  // string longestPalindrome(string s) {
  //   int n = s.size();
  //   string max_len_substring = "";
  //   for (int i = 0; i < n; i++) {
  //     string temp;
  //     for (int j = i; j < n; j++) {
  //       temp.push_back(s[j]);
  //       if (is_palindrome(temp)) {
  //         max_len_substring =
  //             temp.size() > max_len_substring.size() ? temp :
  //             max_len_substring;
  //       }
  //     }
  //   }
  //   return max_len_substring;
  // }
  string longestPalindrome(string s) {
    string max_substring = "";
    int n = s.size();
    for (int i = 0; i < n; i++) {
      auto odd = expand_and_check_palindrome(s, i - 1, i + 1, n);
      auto even = expand_and_check_palindrome(s, i, i + 1, n);
      int len_odd = odd[1] - odd[0] + 1;
      int len_even = even[1] - even[0] + 1;
      if (len_odd > len_even) {
        if (len_odd > max_substring.size()) {
          max_substring = s.substr(odd[0], len_odd);
        }
      } else {
        if (len_even > max_substring.size()) {
          max_substring = s.substr(even[0], len_even);
        }
      }
    }
    return max_substring;
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("cbbd");
  return 0;
}
