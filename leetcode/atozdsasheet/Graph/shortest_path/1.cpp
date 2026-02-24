// Problem Statement: Given a Directed Acyclic Graph of N vertices from 0 to N-1
// and M edges and a 2D Integer array edges, where there is a directed edge from
// vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all
// i. Find the shortest path from source vertex to all the vertices and if it is
// impossible to reach any vertex, then return -1 for that vertex. The source
// vertex is assumed to be 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> find_shortest_distance(vector<vector<int>> &edges, int N, int M,
                                     int src) {
    vector<pair<int, int>> adj[N];

    for (auto val : edges) {
      adj[val[0]].push_back({val[1], val[2]});
    }

    vector<int> distance(N, INT_MAX);
    queue<pair<int, int>> q;

    distance[src] = 0;
    q.push({src, 0});

    while (!q.empty()) {
      auto [node, dist] = q.front();
      q.pop();

      for (auto [neighbor, b] : adj[node]) {
        if (distance[neighbor] == INT_MAX) {
          distance[neighbor] = distance[node] + b;
          q.push({neighbor, distance[b]});
        }
      }
    }

    for (int i = 0; i < N; i++) {
      if (distance[i] == INT_MAX)
        distance[i] = -1;
    }

    return distance;
  }
};
