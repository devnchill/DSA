// 547. Number of Provinces
// Medium
// Topics
// premium lock icon
// Companies
// There are n cities. Some of them are connected, while some are not. If city a
// is connected directly with city b, and city b is connected directly with city
// c, then city a is connected indirectly with city c.
//
// A province is a group of directly or indirectly connected cities and no other
// cities outside of the group.
//
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
// ith city and the jth city are directly connected, and isConnected[i][j] = 0
// otherwise.
//
// Return the total number of provinces.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int n;
  void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited) {
    visited[u] = true;
    for (int &v : adj[u]) {
      if (!visited[v]) {
        dfs(adj, v, visited);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    n = isConnected.size();
    vector<bool> visited(n, false);
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(adj, i, visited);
        count++;
      }
    }
    return count;
  }
};
