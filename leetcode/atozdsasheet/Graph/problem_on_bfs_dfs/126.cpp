// A transformation sequence from word beginWord to word endWord using a
// dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
// such that:
//
// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to
// be in wordList. sk == endWord Given two words, beginWord and endWord, and a
// dictionary wordList, return all the shortest transformation sequences from
// beginWord to endWord, or an empty list if no such sequence exists. Each
// sequence should be returned as a list of the words [beginWord, s1, s2, ...,
// sk].
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    // make a hash set of words
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord))
      return {};
    wordSet.insert(beginWord);

    // use BFS to build all adjacency list (shortest path only) from the end.
    queue<string> q;
    q.push(endWord);

    unordered_map<string, vector<string>>
        parent; // adjList, recording parents from shortest path
    unordered_map<string, int>
        parentStep;     // record the first time we added parennts (ensure only
                        // adding shortest path parent)
    bool found = false; // if beginWord found or not

    int step = 0; // calculate current loop No.
    while (!q.empty() && !found) {
      int sz = q.size();
      while (sz--) {
        string cur = q.front();
        q.pop();
        wordSet.erase(cur); // remove from set, avoid further visit

        // replace letters and extend path;
        for (int i = 0; i < cur.size(); ++i) {
          string temp(cur);
          char c = temp[i];
          for (int j = 0; j < 26; ++j) {
            if (j + 'a' == c)
              continue; // skip the original char
            temp[i] = j + 'a';

            // skip if already visited
            if (!wordSet.count(temp))
              continue;

            // skip if not the first loop to add parent for this word.
            if (parentStep.count(temp) && parentStep[temp] != step)
              continue;
            // if it is the first time, enqueue.
            if (parent[temp].empty()) {
              q.push(temp);
            }

            // add parents, set current step.
            parent[temp].push_back(cur);
            parentStep[temp] = step;

            // if find with the shortest path, stop at next outer loop.
            // (finish current layer to find other possible shortest path)
            if (temp == beginWord) {
              found = true;
            }
          }
        }
      }
      step++;
    }

    if (!found)
      return {};

    // now we have all parents for each node that lead the shortest path
    // use DFS to construct the solutions.
    vector<vector<string>> res;
    vector<string> path = {beginWord};
    dfs(endWord, parent, path, res);
    return res;
  }

  void dfs(const string &end,
           const unordered_map<string, vector<string>> &parent,
           vector<string> &path, vector<vector<string>> &res) {
    if (!path.empty() && path.back() == end) {
      res.push_back(path);
      return;
    }

    for (const string &word : parent.at(path.back())) {
      path.push_back(word);
      dfs(end, parent, path, res);
      path.pop_back();
    }
  }
};
