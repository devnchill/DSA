/*
Count the Number of Set Bits
0
100Easy

Given an integer n, return the number of set bits (1s) in its binary
representation.


Can you solve it in O(log n) time complexity?
Examples:

Input: n = 5

Output: 2

Explanation: The binary representation of 5 is 101, which has 2 set bits.

Input: n = 15

Output: 4

Explanation: The binary representation of 15 is 1111, which has 4 set bits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSetBits(int n) {
    string binary = "";
    int s = 0;
    while (n > 0) {
      n % 2 == 0 ? binary.push_back('0') : binary.push_back('1');
      n /= 2;
    }
    for (auto it : binary) {
      if (it == '1')
        s++;
    }
    return s;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.countSetBits(15);
  return 0;
}
