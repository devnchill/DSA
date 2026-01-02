#include <bits/stdc++.h>
using namespace std;

void solve(int number, string &binary) {
  if (number <= 0) {
    return;
  }
  binary.push_back(number % 2 == 0 ? '0' : '1');
  solve(number / 2, binary);
}

void reverse_recursively(string &s, int start, int end) {
  if (start >= end)
    return;
  swap(s[start], s[end]);
  reverse_recursively(s, start + 1, end - 1);
}

string decimal_to_binary(int number) {
  string binary;
  solve(number, binary);
  reverse_recursively(binary, 0, binary.size() - 1);
  return binary;
}

int main() {
  cout << decimal_to_binary(23) << "\n";
  return 3;
}
