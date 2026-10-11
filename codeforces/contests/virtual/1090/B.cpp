// So, Macaque has passed his first challenge (and is not acknowledging your
// help whatsoever). After all, it was only given to him so he could engage in
// his greatest pleasure — crunching on desiccated freezedried hamburgers and
// yelling 'trivial' at the screen. However, he has another, much more important
// task ahead of him, and he has once again enlisted you to help him.
//
// You are given 7
//  integers a1,a2,…,a7
// .
//
// You must negate 6
//  out of the 7
//  integers (that is, multiply them by −1
// ). Over all possible ways to negate 6
//  out of the 7
//  integers, find the maximum possible sum of a
// .
//
// Input
// Each test contains multiple test cases. The first line contains the number of
// test cases t
//  (1≤t≤6767
// ). The description of the test cases follows.
//
// The first and only line of each test case contains 7
//  space-separated integers a1,a2,…,a7
//  (−67≤ai≤67
// ).
//
// Output
// For each test case, output the maximum sum of a
//  after negating 6
//  out of the 7
//  integers, on a new line.
//
// Example
// InputCopy
// 4
// 41 41 41 41 41 41 41
// 6 9 4 20 6 7 67
// 1 2 3 4 5 6 7
// 6 7 6 7 6 7 6
// OutputCopy
// -205
// 15
// -14
// -31

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    vector<int> vals;
    for (int i = 0; i < 7; i++) {
      int curr;
      cin >> curr;
      vals.push_back(curr);
    }
    sort(vals.begin(), vals.end());
    int sum = 0;
    for (int i = 0; i < vals.size() - 1; i++) {
      sum += -vals[i];
    }
    cout << sum + vals.back() << "\n";
  }
}
