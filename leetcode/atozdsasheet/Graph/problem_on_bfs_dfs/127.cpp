// 127. Word Ladder
// Hard
// Topics
// premium lock icon
// Companies
// A transformation sequence from word beginWord to word endWord using a
// dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
// such that:
//
// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to
// be in wordList. sk == endWord Given two words, beginWord and endWord, and a
// dictionary wordList, return the number of words in the shortest
// transformation sequence from beginWord to endWord, or 0 if no such sequence
// exists.
//
//
//
// Example 1:
//
// Input: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log","cog"] Output: 5 Explanation: One shortest
// transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is
// 5 words long. Example 2:
//
// Input: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log"] Output: 0 Explanation: The endWord "cog" is
// not in wordList, therefore there is no valid transformation sequence.

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    set<string> s;
    for (string word : wordList)
      s.insert(word);
    if (s.count(endWord) == 0)
      return 0;
    queue<string> q;
    q.push(beginWord);

    set<string> visited;
    visited.insert(beginWord);
    int changes = 1;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        string word = q.front();
        q.pop();
        if (word == endWord)
          return changes;
        for (int j = 0; j < word.size(); j++) {
          char original = word[j];
          for (int k = 'a'; k <= 'z'; k++) {
            word[j] = (char)k;
            if (s.count(word) == 1 && visited.count(word) == 0) {
              q.push(word);
              visited.insert(word);
            }
          }
          word[j] = original;
        }
      }
      changes++;
    }
    return 0;
  }
};
