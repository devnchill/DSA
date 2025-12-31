/*
Find minimum number of coins

Problem Statement: Given a value V, if we want to make a change for V Rs, and we
have an infinite supply of each of the denominations in Indian currency, i.e.,
we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued
coins/notes, what is the minimum number of coins and/or notes needed to make the
change.
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int N) {
  int res = 0;
  vector<int> money = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
  while (N > 0) {
    for (int mo : money) {
      if (mo <= N) {
        res += N / mo;
        N = N % mo;
      }
    }
  }
  return res;
}
int main() {
  cout << solve(556) << "\n";
  return 0;
}
