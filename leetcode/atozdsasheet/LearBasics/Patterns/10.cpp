/*
Problem Statement: Given an integer N, print the following pattern :

Examples:

Input Format: N = 3
Result:
  *
  **
  ***
  **
  *
Input Format: N = 6
Result:
     *
     **
     ***
     ****
     *****
     ******
     *****
     ****
     ***
     **
     *
*/
#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
  solve(6);
  return 0;
}
