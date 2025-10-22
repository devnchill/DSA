/*
Problem Statement: Given an integer N, print the following pattern :

Examples:

Input Format: N = 3
Result:
  *
 ***
*****
Input Format: N = 6
Result:
     *
    ***
   *****
  *******
 *********
***********

*/

#include <bits/stdc++.h>
using namespace std;

void solve(int N) {
  for (int i = 1; i <= N; i++) {
    for (int j = N - i; j > 0; j--) {
      cout << " ";
    }
    for (int j = 0; j < 2 * i - 1; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
  solve(3);
  return 0;
}
