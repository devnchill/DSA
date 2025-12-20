/*
 * Print numbers from N to 1
 */
#include <bits/stdc++.h>
using namespace std;

void recurse(int n) {
  if (n < 1) {
    return;
  }
  cout << n << "\n";
  recurse(n - 1);
}
int main(int argc, char *argv[]) {
  if (argc != 2)
    cerr << "Invalid Input";
  int n = stoi(argv[1]);
  recurse(n);
  return 0;
}
