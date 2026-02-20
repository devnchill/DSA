// There is an undirected graph with n nodes, where each node is numbered
// between 0 and n - 1. You are given a 2D array graph, where graph[u] is an
// array of nodes that node u is adjacent to. More formally, for each v in
// graph[u], there is an undirected edge between node u and node v. The graph
// has the following properties:
//
// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such
// that there is no path between them. A graph is bipartite if the nodes can be
// partitioned into two independent sets A and B such that every edge in the
// graph connects a node in set A and a node in set B.
//
// Return true if and only if it is bipartite.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> visited;
  bool dfs(size_t node, vector<vector<int>> &graph) {
    for (int neighbor : graph[node]) {
      if (visited[neighbor] != -1) {
        if (visited[neighbor] == visited[node])
          return false;
        continue;
      }
      visited[neighbor] = 1 - visited[node];
      if (!dfs(neighbor, graph))
        return false;
    }
    return true;
  }

public:
  bool isBipartite(vector<vector<int>> &graph) {
    size_t n = graph.size();
    visited.assign(n, -1);
    for (int i = 0; i < n; i++) {
      if (visited[i] == -1) {
        visited[i] = 0;
        if (!dfs(i, graph))
          return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  // vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  cout << s.isBipartite(graph) << " is result\n";
}
