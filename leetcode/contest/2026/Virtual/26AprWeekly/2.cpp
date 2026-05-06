// Q2. Sort Vowels by Frequency
// Medium
// 4 pt.
// You are given a string s consisting of lowercase English characters.
//
// Rearrange only the vowels in the string so that they appear in non-increasing
// order of their frequency.
//
// If multiple vowels have the same frequency, order them by the position of
// their first occurrence in s.
//
// Return the modified string.
//
// Vowels are 'a', 'e', 'i', 'o', and 'u'.
//
// The frequency of a letter is the number of times it occurs in the string.
//
//
//
// Example 1:
//
// Input: s = "leetcode"
//
// Output: "leetcedo"
//
// Explanation:​​​​​​​
//
// Vowels in the string are ['e', 'e', 'o', 'e'] with frequencies: e = 3, o = 1.
// Sorting in non-increasing order of frequency and placing them back into the
// vowel positions results in "leetcedo". Example 2:
//
// Input: s = "aeiaaioooa"
//
// Output: "aaaaoooiie"
//
// Explanation:​​​​​​​
//
// Vowels in the string are ['a', 'e', 'i', 'a', 'a', 'i', 'o', 'o', 'o', 'a']
// with frequencies: a = 4, o = 3, i = 2, e = 1. Sorting them in non-increasing
// order of frequency and placing them back into the vowel positions results in
// "aaaaoooiie". Example 3:
//
// Input: s = "baeiou"
//
// Output: "baeiou"
//
// Explanation:
//
// Each vowel appears exactly once, so all have the same frequency.
// Thus, they retain their relative order based on first occurrence, and the
// string remains unchanged.
//
//
// Constraints:
//
// 1 <= s.length <= 105
// s consists of lowercase English letters

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string sortVowels(string s) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    unordered_map<char, int> freq;
    unordered_map<char, int> firstPos;
    vector<char> extracted;

    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (vowels.count(c)) {
        freq[c]++;
        extracted.push_back(c);

        if (!firstPos.count(c)) {
          firstPos[c] = i;
        }
      }
    }

    sort(extracted.begin(), extracted.end(), [&](char a, char b) {
      if (freq[a] != freq[b])
        return freq[a] > freq[b];
      return firstPos[a] < firstPos[b];
    });

    int idx = 0;
    for (char &c : s) {
      if (vowels.count(c)) {
        c = extracted[idx++];
      }
    }

    return s;
  }
};
