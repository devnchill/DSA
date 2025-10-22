/*
Problem Statement: Given an integer N, print the following pattern :


Here, N = 5.

Examples:

Input Format: N = 3
Result:
1
2 2
3 3 3

Input Format: N = 6
Result:
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
6 6 6 6 6 6

*/
#include <bits/stdc++.h>
using namespace std;

void solve(int N) {
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < i; j++) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main() {
  solve(6);
  return 0;
}
