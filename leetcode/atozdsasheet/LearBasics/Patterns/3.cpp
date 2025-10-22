/*
Problem Statement: Given an integer N, print the following pattern :


Here, N = 5.

Examples:

Input Format: N = 3
Result:
1
1 2
1 2 3

Input Format: N = 6
Result:
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6

*/

#include <bits/stdc++.h>
using namespace std;
void solve(int N) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}

int main() {
  solve(3);
  return 0;
}
