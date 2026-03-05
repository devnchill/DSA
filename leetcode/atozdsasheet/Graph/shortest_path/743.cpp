// 743. Network Delay Time
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a network of n nodes, labeled from 1 to n. You are also given
// times, a list of travel times as directed edges times[i] = (ui, vi, wi),
// where ui is the source node, vi is the target node, and wi is the time it
// takes for a signal to travel from source to target.
//
// We will send a signal from a given node k. Return the minimum time it takes
// for all the n nodes to receive the signal. If it is impossible for all the n
// nodes to receive the signal, return -1.
//
//
//
// Example 1:
//
//
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:
//
// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:
//
// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1
//
//
// Constraints:
//
// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // 1. Build adjacency list
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &val : times) {
      adj[val[0]].push_back({val[1], val[2]}); // {neighbor, weight}
    }

    // 2. Distance array + priority queue
    vector<int> dist(n + 1, 1e9);
    dist[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, k}); // {time_so_far, node}

    // 3. Dijkstra loop
    while (!pq.empty()) {
      auto [curr_time, u] = pq.top();
      pq.pop();

      // Skip if we already found a better path
      if (curr_time > dist[u])
        continue;

      for (auto &[v, w] : adj[u]) {
        if (curr_time + w < dist[v]) {
          dist[v] = curr_time + w;
          pq.push({dist[v], v});
        }
      }
    }

    // 4. Find the max time to reach all nodes
    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == 1e9 ? -1 : ans;
  }
};
