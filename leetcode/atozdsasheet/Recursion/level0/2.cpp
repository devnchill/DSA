/*
 * Print numbers from 1 to N
 */
#include <bits/stdc++.h>
using namespace std;

void recurse(int n, int N) {
  if (n > N) {
    return;
  }
  cout << n << "\n";
  recurse(n + 1, N);
}

int main(int argc, char *argv[]) {
  if (argc != 2)
    cerr << "Invalid Input";
  int N = stoi(argv[1]);
  recurse(1, N);
  return 0;
}
