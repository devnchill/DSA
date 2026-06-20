#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long dfs(int u, vector<vector<int>> &graph, vector<int> &baseTime) {
    if (graph[u].empty())
      return baseTime[u];
    long long mn = LLONG_MAX;
    long long mx = LLONG_MIN;
    for (int v : graph[u]) {
      long long childFinish = dfs(v, graph, baseTime);
      mn = min(mn, childFinish);
      mx = max(mx, childFinish);
    }
    return mx + (mx - mn) + baseTime[u];
  }

public:
  long long finishTime(int n, vector<vector<int>> &edges,
                       vector<int> &baseTime) {
    vector<vector<int>> graph(n);
    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];
      graph[u].push_back(v);
    }
    return dfs(0, graph, baseTime);
  }
};
