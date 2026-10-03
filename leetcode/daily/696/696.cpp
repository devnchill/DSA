// 696. Count Binary Substrings
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a binary string s, return the number of non-empty substrings that have
// the same number of 0's and 1's, and all the 0's and all the 1's in these
// substrings are grouped consecutively.
//
// Substrings that occur multiple times are counted the number of times they
// occur.
//
//
//
// Example 1:
//
// Input: s = "00110011"
// Output: 6
// Explanation: There are 6 substrings that have equal number of consecutive 1's
// and 0's: "0011", "01", "1100", "10", "0011", and "01". Notice that some of
// these substrings repeat and are counted the number of times they occur. Also,
// "00110011" is not a valid substring because all the 0's (and 1's) are not
// grouped together. Example 2:
//
// Input: s = "10101"
// Output: 4
// Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
// number of consecutive 1's and 0's.
//
//
// Constraints:
//
// 1 <= s.length <= 105
// s[i] is either '0' or '1'.

#include <bits/stdc++.h>
using namespace std;

// METHOD 1
// 1. Generate all possible substring
// 2. Count frequency of 1s and 0s
// 3. Check if they are equal
// 4. increament result if they are
// 5. return count
// Just realised that it requires grouped 1s and 0s lmao
class Solution0 {
public:
  int countBinarySubstrings(string s) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      string substring;
      for (int j = i; j < n; j++) {
        substring.push_back(s[j]);
        if (count(substring.begin(), substring.end(), '0') ==
            count(substring.begin(), substring.end(), '1'))
          res++;
      }
    }
    return res;
  }
};

// METHOD 2
class Solution {
public:
  int countBinarySubstrings(string s) {
    int n = s.size();
    char curr = s[0];
    size_t count = 1;
    vector<int> a;
    for (int i = 1; i < n; i++) {
      if (s[i] != curr) {
        curr = s[i];
        a.push_back(count);
        count = 0;
      }
      count++;
    }
    a.push_back(count);
    int res = 0;
    for (int i = 0; i < a.size() - 1; i++) {
      res += min(a[i], a[i + 1]);
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.countBinarySubstrings("0011");
}
