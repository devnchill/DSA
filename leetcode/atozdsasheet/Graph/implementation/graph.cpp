#include <bits/stdc++.h>
using namespace std;

//  Adjacency Matrix
/*
 * input format
 * n m => n node m edges
 * a1 b1
 * a2 b2
 * a3 b3
 * a4 b4
 * .
 * .
 * .
 * am bm
 */

int main1() {
  int n, m;
  cin >> n >> m;
  // undirected graph
  int arr[n + 1][n + 1];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }
  return 0;
}

// using vector of vector of list

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  for (auto val : arr) {
    for (auto v : val) {
      cout << v << ", ";
    }
    cout << "\n";
  }
}
