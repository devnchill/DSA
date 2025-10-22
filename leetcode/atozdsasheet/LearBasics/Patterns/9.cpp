/*
Problem Statement: Given an integer N, print the following pattern :

Examples:

Input Format: N = 3
Result:
  *
 ***
*****
*****
 ***
  *
Input Format: N = 6
Result:
     *
    ***
   *****
  *******
 *********
***********
***********
 *********
  *******
   *****
    ***
     *
*/
#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = n - i; j > 0; j--) {
      cout << " ";
    }
    for (int j = 1; j <= 2 * i - 1; j++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      cout << " ";
    }
    for (int j = (2 * n) - 1 - 2 * (i - 1); j > 0; j--) {
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
  solve(6);
  return 0;
}
