/*
Problem Statement: Given an integer N, print the following pattern :

Here, N = 5.

Examples:

Input Format: N = 3
Result:
*
* *
* * *

Input Format: N = 6
Result:
*
* *
* * *
* * * *
* * * * *
* * * * * *

*/

#include <bits/stdc++.h>
using namespace std;
void solve(int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
  solve(3);
  return 0;
}
