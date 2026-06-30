// 1358. Number of Substrings Containing All Three Characters
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s consisting only of characters a, b and c.
//
// Return the number of substrings containing at least one occurrence of all
// these characters a, b and c.
//
//
//
// Example 1:
//
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the
// characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab",
// "bcabc", "cab", "cabc" and "abc" (again). Example 2:
//
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the
// characters a, b and c are "aaacb", "aacb" and "acb". Example 3:
//
// Input: s = "abc"
// Output: 1
//
//
// Constraints:
//
// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    int count_a = 0, count_b = 0, count_c = 0;
    int left = 0, right = 0;
    int n = s.size();
    int res = 0;

    while (right < n) {
      while (right < n && (count_a == 0 || count_b == 0 || count_c == 0)) {
        switch (s[right]) {
        case 'a':
          count_a++;
          break;
        case 'b':
          count_b++;
          break;
        case 'c':
          count_c++;
          break;
        }
        right++;
      }
      while (count_a && count_b && count_c) {
        res += (n - right + 1);
        switch (s[left]) {
        case 'a':
          count_a--;
          break;
        case 'b':
          count_b--;
          break;
        case 'c':
          count_c--;
          break;
        }
        left++;
      }
    }
    while (count_a && count_b && count_c) {
      res += 1;
      switch (s[left]) {
      case 'a':
        count_a--;
        break;
      case 'b':
        count_b--;
        break;
      case 'c':
        count_c--;
        break;
      }
      left++;
    }
    return res;
  }
};

class Solution2 {
public:
  int numberOfSubstrings(string s) {
    int len = s.length();
    int left = 0, right = 0;
    // Track frequency of a, b, c
    vector<int> freq(3, 0);
    int total = 0;

    while (right < len) {
      // Add character at right pointer to frequency array
      char curr = s[right];
      freq[curr - 'a']++;

      // While we have all required characters
      while (hasAllChars(freq)) {
        // All substrings from current window to end are valid
        // Add count of these substrings to result
        total += len - right;

        // Remove leftmost character and move left pointer
        char leftChar = s[left];
        freq[leftChar - 'a']--;
        left++;
      }

      right++;
    }

    return total;
  }

private:
  bool hasAllChars(vector<int> &freq) {
    // Check if we have at least one of each character
    return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
  }
};
