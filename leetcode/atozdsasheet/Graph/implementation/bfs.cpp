// Problem Statement: Given an undirected graph, return a vector of all nodes by
// traversing the graph using breadth-first search (BFS).

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int v, vector<int> adj[]) {
  vector<int> vis(v);
  vis[0] = 1;
  queue<int> q;
  q.push(0);
  vector<int> bfs;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int val : adj[curr]) {
      if (!vis[val]) {
        vis[val] = 1;
        q.push(val);
      }
    }
  }
  return bfs;
}
