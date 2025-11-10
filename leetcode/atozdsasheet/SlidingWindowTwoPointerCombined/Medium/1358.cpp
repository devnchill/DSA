/*
1358. Number of Substrings Containing All Three Characters
Medium
Topics
premium lock icon
Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these
characters a, b and c.

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters
a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab",
"cabc" and "abc" (again). Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters
a, b and c are "aaacb", "aacb" and "acb". Example 3:

Input: s = "abc"
Output: 1

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // METHOD 1 BRUTEFORCE
  // generate all substrings and check whether it satisfies the condition
  // int numberOfSubstrings(string s) {
  //   int res = 0;
  //   int n = s.size();
  //   for (int i = 0; i < n; i++) {
  //     vector<int> freq(3, 0);
  //     for (int j = i; j < n; j++) {
  //       freq[s[j] - 'a']++;
  //       if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
  //         res++;
  //     }
  //   }
  //   return res;
  // }
  // METHOD 2 sliding window
  int numberOfSubstrings(string s) {
    int left = 0, n = s.size(), res = 0;
    vector<int> freq(3, 0);
    for (int right = 0; right < n; right++) {
      freq[s[right] - 'a']++;
      while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
        res += (n - right);
        freq[s[left] - 'a']--;
        left++;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.numberOfSubstrings("abcabc");
  return 0;
}
