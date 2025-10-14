// Check if a number is odd or not
#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  string binary = "";
  while (n > 0) {
    n % 2 == 0 ? binary.push_back('0') : binary.push_back('1');
    n /= 2;
  }
  return (binary[binary.size() - 1] == '0');
}
