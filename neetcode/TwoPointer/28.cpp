/*
28. Find the Index of the First Occurrence in a String
Easy
Topics
premium lock iconCompanies

Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.



Constraints:

    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int strStr(string haystack, string needle) {
    int hsize = haystack.size();
    int nsize = needle.size();
    int i = 0;
    int j = 0;
    int index = -1;
    while (i < hsize) {
      if (haystack[i] == needle[j]) {
        if (j == 0)
          index = i;
        j++;
        if (nsize == j)
          return index;
      } else {
        if (j > 0) {
          i = index;
        }
        j = 0;
        index = -1;
      }
      i++;
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.strStr("mississippi", "issip");
  return 0;
}
