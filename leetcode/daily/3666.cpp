// 3666. Minimum Operations to Equalize Binary String
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a binary string s, and an integer k.
//
// In one operation, you must choose exactly k different indices and flip each
// '0' to '1' and each '1' to '0'.
//
// Return the minimum number of operations required to make all characters in
// the string equal to '1'. If it is not possible, return -1.
//
//
//
// Example 1:
//
// Input: s = "110", k = 1
//
// Output: 1
//
// Explanation:
//
// There is one '0' in s.
// Since k = 1, we can flip it directly in one operation.
// Example 2:
//
// Input: s = "0101", k = 3
//
// Output: 2
//
// Explanation:
//
// One optimal set of operations choosing k = 3 indices in each operation is:
//
// Operation 1: Flip indices [0, 1, 3]. s changes from "0101" to "1000".
// Operation 2: Flip indices [1, 2, 3]. s changes from "1000" to "1111".
// Thus, the minimum number of operations is 2.
//
// Example 3:
//
// Input: s = "101", k = 2
//
// Output: -1
//
// Explanation:
//
// Since k = 2 and s has only one '0', it is impossible to flip exactly k
// indices to make all '1'. Hence, the answer is -1.
//
//
// Constraints:
//
// 1 <= s.length <= 105
// s[i] is either '0' or '1'.
// 1 <= k <= s.length

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(string s, int k) {
    int n = s.size(), m = 0;
    vector<int> dist(n + 1, INT_MAX);
    vector<set<int>> nodeSets(2);
    for (int i = 0; i <= n; i++) {
      nodeSets[i % 2].insert(i);
      if (i < n && s[i] == '0') {
        m++;
      }
    }
    queue<int> q;
    q.push(m);
    dist[m] = 0;
    nodeSets[m % 2].erase(m);
    while (!q.empty()) {
      m = q.front();
      q.pop();
      int c1 = max(k - n + m, 0), c2 = min(m, k);
      int lnode = m + k - 2 * c2, rnode = m + k - 2 * c1;
      auto &nodeSet = nodeSets[lnode % 2];
      for (auto iter = nodeSet.lower_bound(lnode);
           iter != nodeSet.end() && *iter <= rnode;) {
        int m2 = *iter;
        dist[m2] = dist[m] + 1;
        q.push(m2);
        iter = next(iter);
        nodeSet.erase(m2);
      }
    }
    return dist[0] == INT_MAX ? -1 : dist[0];
  }
};
