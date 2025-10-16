/*
204. Count Primes
Medium
Topics
premium lock icon
Companies
Hint
Given an integer n, return the number of prime numbers that are strictly less
than n.



Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0


Constraints:

0 <= n <= 5 * 106
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countPrimes(int n) {
    if (n < 2)
      return 0;
    int count = 0;
    unordered_map<int, bool> m;
    for (int b = 2; b <= n; b++) {
      m[b] = false;
    }
    int p;
    for (int k = 2; k < n; k++) {
      if (m[k] == false) {
        p = k;
        for (int j = 2 * p; j < n; j += p) {
          m[j] = true;
        }
      }
    }
    for (int a = 2; a < n; a++) {
      if (m[a] == false)
        count++;
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.countPrimes(5);
  return 0;
}
