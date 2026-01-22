// Problem Statement: Given an undirected graph, return a vector of all nodes by
// traversing the graph using depth-first search (DFS).

#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);
  vector<int> res;
  stack<int> st;
  st.push(0);
  vis[0] = 1;
  while (!st.empty()) {
    int node = st.top();
    st.pop();
    res.push_back(node);
    for (int neigh : adj[node]) {
      vis[neigh] = 1;
      st.push(neigh);
    }
  }
  return res;
}
