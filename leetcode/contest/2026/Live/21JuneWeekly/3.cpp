#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long shortestPath(int n, vector<vector<int>> &edges, string labels,
                         int k) {

    vector<vector<pair<int, int>>> adj(n);
    for (auto &e : edges) {
      adj[e[0]].push_back({e[1], e[2]});
    }
    const long long INF = (long long)4e18;
    vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));
    using T = tuple<long long, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    dist[0][1] = 0;
    pq.push({0, 0, 1});
    while (!pq.empty()) {
      auto [cost, u, streak] = pq.top();
      pq.pop();
      if (cost != dist[u][streak])
        continue;
      for (auto &[v, w] : adj[u]) {
        int newStreak;
        if (labels[v] == labels[u]) {
          newStreak = streak + 1;
          if (newStreak > k)
            continue;
        } else {
          newStreak = 1;
        }
        long long newCost = cost + w;
        if (newCost < dist[v][newStreak]) {
          dist[v][newStreak] = newCost;
          pq.push({newCost, v, newStreak});
        }
      }
    }
    long long ans = INF;
    for (int s = 1; s <= k; s++) {
      ans = min(ans, dist[n - 1][s]);
    }
    return (ans == INF) ? -1 : ans;
  }
};
