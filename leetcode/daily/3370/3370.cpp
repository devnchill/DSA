/*
3370. Smallest Number With All Set Bits
Easy
Topics
premium lock icon
Companies
Hint
You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary
representation of x contains only set bits



Example 1:

Input: n = 5

Output: 7

Explanation:

The binary representation of 7 is "111".

Example 2:

Input: n = 10

Output: 15

Explanation:

The binary representation of 15 is "1111".

Example 3:

Input: n = 3

Output: 3

Explanation:

The binary representation of 3 is "11".



Constraints:

1 <= n <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // METHOD 1
  // int smallestNumber(int n) {
  //   int curr = n;
  //   while (true) {
  //     string binary = getBinary(curr);
  //     if (isSet(binary))
  //       return curr;
  //     else
  //       curr++;
  //   }
  // }

  // METHOD 2
  // int smallestNumber(int n) {
  //   int curr = 1;
  //   while (curr <= n) {
  //     curr = curr * 2 + 1;
  //   }
  //   return curr;
  // }

  // METHOD 3
  int smallestNumber(int n) {
    int bits = 0;
    int temp = n;
    while (temp > 0) {
      bits++;
      temp >>= 1;
    }
    return (1 << bits) - 1;
  }

private:
  string getBinary(int n) {
    if (n == 0)
      return "0";
    string curr = "";
    while (n > 0) {
      curr.push_back('0' + (n % 2));
      n /= 2;
    }
    reverse(curr.begin(), curr.end());
    return curr;
  }

  bool isSet(string binary) {
    for (char &ch : binary)
      if (ch != '1')
        return false;
    return true;
  }
};

int main() {
  Solution s;
  cout << s.smallestNumber(10);
  return 0;
}
