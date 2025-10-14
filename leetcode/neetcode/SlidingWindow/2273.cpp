/*
2273. Find Resultant Array After Removing Anagrams
Easy
Topics
premium lock iconCompanies
Hint

You are given a 0-indexed string array words, where words[i] consists of
lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i
- 1] and words[i] are anagrams, and delete words[i] from words. Keep performing
this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the
indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase using all the original letters exactly once. For example, "dacb"
is an anagram of "abdc".
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> removeAnagrams(vector<string> &words) {
    int i = 0;
    int j = 1;
    vector<string> res;
    res.push_back(words[i]);
    while (j < words.size()) {
      if (isAnagram(words[i], words[j])) {
        j++;
      } else {
        res.push_back(words[j]);
        i = j;
        j++;
      }
    }
    return res;
  }

private:
  bool isAnagram(string &s1, string &s2) {
    map<char, int> m;
    map<char, int> n;
    for (auto it : s1) {
      m[it]++;
    }
    for (auto it : s2) {
      n[it]++;
    }
    if (m == n)
      return true;
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> v = {"abba", "baba", "bbaa", "cd", "cd"};
  vector<string> res = s.removeAnagrams(v);
  for (auto it : res) {
    cout << it << endl;
  }
  return 0;
}
