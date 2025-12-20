// Sum of first N natural numbers

#include <bits/stdc++.h>
using namespace std;
int sum_of_N(int n) {
  if (n == 0)
    return 0;
  return n + sum_of_N(n - 1);
}

int main(int argc, char *argv[]) {
  cout << sum_of_N(6);
  return 0;
}
