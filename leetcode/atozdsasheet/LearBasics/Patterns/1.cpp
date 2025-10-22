/*
Problem Statement: Given an integer N, print the following pattern.
Examples:

Example 1:
Input: N = 3
Output:
* * *
* * *
* * *


Example 2:
Input: N = 6
Output:
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *

*/

#include <iostream>
using std::cout;
using std::endl;
void solve(int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
  solve(3);
  return 0;
}
