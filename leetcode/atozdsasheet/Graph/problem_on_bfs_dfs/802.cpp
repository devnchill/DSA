// 802. Find Eventual Safe States
// Medium
// Topics
// premium lock icon
// Companies
// There is a directed graph of n nodes with each node labeled from 0 to n - 1.
// The graph is represented by a 0-indexed 2D integer array graph where graph[i]
// is an integer array of nodes adjacent to node i, meaning there is an edge
// from node i to each node in graph[i].
//
// A node is a terminal node if there are no outgoing edges. A node is a safe
// node if every possible path starting from that node leads to a terminal node
// (or another safe node).
//
// Return an array containing all the safe nodes of the graph. The answer should
// be sorted in ascending order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> state; // 0=unvisited, 1=visiting, 2=safe

  bool dfs(int node, vector<vector<int>> &graph) {
    if (state[node] != 0)
      return state[node] == 2; // already visited
    state[node] = 1;           // mark as visiting
    for (int nei : graph[node]) {
      if (state[nei] == 1 || !dfs(nei, graph))
        return false; // cycle or leads to unsafe node
    }
    state[node] = 2; // mark as safe
    return true;
  }

public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    state.assign(n, 0);
    vector<int> safeNodes;
    for (int i = 0; i < n; i++) {
      if (dfs(i, graph))
        safeNodes.push_back(i);
    }
    return safeNodes;
  }
};
