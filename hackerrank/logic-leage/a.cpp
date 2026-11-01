// The expedition’s first stop is the Cinder Moon, where the crew will have
// limited time to unload supplies. Mission control has set a target mass for
// the cargo pod based on the ship’s capacity and the equipment needed at the
// landing site.
//
// The pod will carry exactly two modules. Each module has a recorded mass
// rating. The inventory may contain multiple modules with the same rating;
// modules at different positions in the inventory are considered separate
// items.
//
// For any pair of distinct modules, let S be their combined mass and T be the
// target mass. Find the smallest possible value of abs(S - T).
//
// Input Format
//
// The first line contains two space-separated integers:
//
// N: the number of cargo modules.
// T: the target total mass.
// The second line contains N space-separated integers, w1, w2, ..., wN, where
// wi is the mass rating of the module at position i.
//
// Constraints
//
// 2 <= N <= 200000
// 1 <= wi <= 1000000000
// 0 <= T <= 2000000000
// Output Format
//
// Print one integer: the smallest possible absolute difference between T and
// the combined mass of any two modules at different positions.
//
// In other words, print the minimum value of |wi + wj - T| over all pairs of
// indices i and j such that 1 <= i < j <= N.
//
// Sample Input 0
//
// 6 30
// 3 8 12 17 21 26
// Sample Output 0
//
// 1
// Sample Input 1
//
// 2 100
// 45 60
// Sample Output 1
//
// 5

#include <bits/stdc++.h>
#include <climits>
using namespace std;

#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// METHOD 1 Bruteforce
int main1() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, T;
  cin >> N >> T;
  vector<int> wts;
  for (int i = 0; i < N; i++) {
    int wt;
    cin >> wt;
    wts.push_back(wt);
  }
  int res = INT_MAX;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      res = min(res, abs(wts[i] + wts[j] - T));
    }
  }
  cout << res;
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, T;
  cin >> N >> T;
  vector<int> wts;
  for (int i = 0; i < N; i++) {
    int wt;
    cin >> wt;
    wts.push_back(wt);
  }
  sort(wts.begin(), wts.end());
  int start = 0, end = N - 1;
  int res = INT_MAX;
  while (start < end) {
    int sum = wts[start] + wts[end];
    res = min(res, abs(wts[start] + wts[end] - T));
    if (sum > T) {
      end--;
    } else {
      start++;
    }
  }
  cout << res;
  return 0;
}
