/*Check if the i-th bit is Set or Not
0
100Easy

Given two integers n and i, return true if the ith bit in the binary
representation of n (counting from the least significant bit, 0-indexed) is set
(i.e., equal to 1). Otherwise, return false. Examples:

Input: n = 5, i = 0

Output: true

Explanation: Binary representation of 5 is 101. The 0-th bit from LSB is set
(1).


Input: n = 10, i = 1

Output: true

Explanation: Binary representation of 10 is 1010. The 1-st bit from LSB is set
(1).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool checkIthBit(int n, int i) {
    string binary = "";
    while (n > 0) {
      n % 2 == 0 ? binary.push_back('0') : binary.push_back('1');
      n /= 2;
    }
    if (i > binary.size())
      return false;
    return binary[i] == '1';
  }
};
