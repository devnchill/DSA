// During the expedition, the station records a load reading after each crew
// movement through the airlock. Sudden changes in load can destabilize the
// station, so mission control reviews continuous stretches of readings.
//
// A stretch is considered stable when the difference between its highest and
// lowest readings is no greater than the station’s stability limit D.
//
// Given the readings and the limit D, count how many nonempty, contiguous
// stretches are stable. A stretch is contiguous if it contains every reading
// between its first and last positions.
//
// Input Format
//
// The first line contains two space-separated integers:
//
// N: the number of load readings.
// D: the maximum permitted difference between the highest and lowest readings
// in a stable stretch. The second line contains N space-separated integers, a1,
// a2, ..., aN, where ai is the load reading recorded after the ith crew
// movement.
//
// Constraints
//
// 1 <= N <= 200000
// 0 <= D <= 1000000000
// -1000000000 <= ai <= 1000000000
// Output Format
//
// Print one integer: the number of nonempty contiguous stretches whose highest
// reading minus their lowest reading is at most D.
//
// Sample Input 0
//
// 1 0
// -5
// Sample Output 0
//
// 1
// Sample Input 1
//
// 1 7
// 12
// Sample Output 1
//
// 1

#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, D;
  cin >> N >> D;
  deque<int> dq_max;
  deque<int> dq_min;
  vector<int> v;
  long long res = 0;
  for (int i = 0; i < N; i++) {
    int in;
    cin >> in;
    v.push_back(in);
  }
  int left = 0;
  for (int right = 0; right < N; right++) {
    while (!dq_min.empty() && v[dq_min.back()] >= v[right]) {
      dq_min.pop_back();
    }
    dq_min.push_back(right);
    while (!dq_min.empty() && dq_min.front() < left) {
      dq_min.pop_front();
    }
    while (!dq_max.empty() && v[dq_max.back()] <= v[right]) {
      dq_max.pop_back();
    }
    dq_max.push_back(right);
    while (!dq_max.empty() && dq_max.front() < left) {
      dq_max.pop_front();
    }
    while (v[dq_max.front()] - v[dq_min.front()] > D) {
      left++;
      while (!dq_min.empty() && dq_min.front() < left) {
        dq_min.pop_front();
      }
      while (!dq_max.empty() && dq_max.front() < left) {
        dq_max.pop_front();
      }
    }
    long long mx = v[dq_max.front()];
    long long mn = v[dq_min.front()];
    if (mx - mn <= D) {
      res += (right - left + 1);
    }
  }
  cout << res;
}
