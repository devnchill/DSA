/*
Q1. Concatenate Non-Zero Digits and Multiply by Sum I
Solved
Easy
3 pt.
You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their
original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

 

Example 1:

Input: n = 10203004

Output: 12340

Explanation:

The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
Therefore, the answer is x * sum = 1234 * 10 = 12340.
Example 2:

Input: n = 1000

Output: 1

Explanation:

The non-zero digit is 1, so x = 1 and sum = 1.
Therefore, the answer is x * sum = 1 * 1 = 1.
 

Constraints:

0 <= n <= 109©leetcode
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long sumAndMultiply(int n) {
    string c = to_string(n);
    long long nn = 0;
    long long sum = 0;
    long long res = 0;
    int i = 10;
    for (char ch : c) {
      if (ch - '0' != 0) {
        sum += (ch - '0');
        nn = nn * i + (ch - '0');
        cout << nn << "\n";
      }
    }
    res = sum * nn;
    return res;
  }
};
