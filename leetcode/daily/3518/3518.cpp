// 3518. Smallest Palindromic Rearrangement II
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a palindromic string s and an integer k.
//
// Return the k-th lexicographically smallest palindromic permutation of s. If
// there are fewer than k distinct palindromic permutations, return an empty
// string.
//
// Note: Different rearrangements that yield the same palindromic string are
// considered identical and are counted once.
//
//
//
// Example 1:
//
// Input: s = "abba", k = 2
//
// Output: "baab"
//
// Explanation:
//
// The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
// Lexicographically, "abba" comes before "baab". Since k = 2, the output is
// "baab". Example 2:
//
// Input: s = "aa", k = 2
//
// Output: ""
//
// Explanation:
//
// There is only one palindromic rearrangement: "aa".
// The output is an empty string since k = 2 exceeds the number of possible
// rearrangements. Example 3:
//
// Input: s = "bacab", k = 1
//
// Output: "abcba"
//
// Explanation:
//
// The two distinct palindromic rearrangements of "bacab" are "abcba" and
// "bacab". Lexicographically, "abcba" comes before "bacab". Since k = 1, the
// output is "abcba".
//
//
// Constraints:
//
// 1 <= s.length <= 104
// s consists of lowercase English letters.
// s is guaranteed to be palindromic.
// 1 <= k <= 106

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long factorial(int n) {
    if (n <= 1)
      return 1;
    return n * factorial(n - 1);
  }
  long long count(vector<int> &freq) {
    long long numer = factorial(accumulate(freq.begin(), freq.end(), 0));
    long long denom = 1;
    for (int i = 0; i < freq.size(); i++) {
      denom *= factorial(freq[i]);
    }
    return numer / denom;
  }

public:
  string smallestPalindrome(string s, int k) {
    vector<int> freq(26, 0);
    string left, mid;
    for (char ch : s)
      freq[ch - 'a']++;
    for (int i = 0; i < freq.size(); i++) {
      if (freq[i] & 1) {
        mid.push_back(char(i + 'a'));
      }
      freq[i] /= 2;
    }
    int left_size = accumulate(freq.begin(), freq.end(), 0);
    while (left.size() < left_size) {
      for (int i = 0; i < 26; i++) {
        if (freq[i] == 0)
          continue;
        freq[i]--;
        long long cnt = count(freq);
        if (cnt < k) {
          k -= cnt;
          freq[i]++;
        } else {
          left.push_back(char(i + 'a'));
          break;
        }
      }
    }
    string right = left;
    reverse(right.begin(), right.end());
    return left + mid + right;
  }
};
