/*
Problem Statement: Given an integer N, print the following pattern :

Examples:

Input Format: N = 3
Result:
1
01
101

Input Format: N = 6
Result:
1
01
101
0101
10101
010101
*/
#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  for (int i = 1; i <= n; i++) {
    int a = i % 2 == 0 ? 0 : 1;
    for (int j = 0; j < i; j++) {
      cout << a;
      a = !a;
    }
    cout << endl;
  }
}

int main() {
  solve(6);
  return 0;
}
