/*
2048. Next Greater Numerically Balanced Number
Medium
Topics
premium lock icon
Companies
Hint
An integer x is numerically balanced if for every digit d in the number x, there
are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly
greater than n.



Example 1:

Input: n = 1
Output: 22
Explanation:
22 is numerically balanced since:
- The digit 2 occurs 2 times.
It is also the smallest numerically balanced number strictly greater than 1.
Example 2:

Input: n = 1000
Output: 1333
Explanation:
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.
Example 3:

Input: n = 3000
Output: 3133
Explanation:
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.


Constraints:

0 <= n <= 106
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // method 1
  // int nextBeautifulNumber(int n) {
  //   int res = n + 1;
  //   while (true) {
  //     vector<int> freq(10, 0);
  //     int temp = res;
  //     while (temp > 0) {
  //       int digit = temp % 10;
  //       freq[digit]++;
  //       temp /= 10;
  //     }
  //     bool is_beautiful = true;
  //     for (int i = 0; i < 10; i++) {
  //       if (freq[i] != 0 && freq[i] != i) {
  //         is_beautiful = false;
  //         break;
  //       }
  //     }
  //     if (is_beautiful)
  //       return res;
  //     res++;
  //   }
  // }

  int nextBeautifulNumber(int n) {
    vector<int> list;
    vector<int> count(10, 0);
    backtrack(0, count, list);
    sort(list.begin(), list.end());
    for (int val : list) {
      if (val > n)
        return val;
    }
    return -1;
  }

private:
  void backtrack(long num, vector<int> &count, vector<int> &list) {
    if (num > 0 && is_beautiful(count)) {
      list.push_back(int(num));
    }
    if (num > 1224444)
      return;
    for (int i = 0; i < 8; ++i) {
      if (count[i] < i) {
        count[i]++;
        backtrack(num * 10 + i, count, list);
        count[i]--;
      }
    }
  }

  bool is_beautiful(vector<int> &count) {
    for (int i = 1; i < 8; i++) {
      if (count[i] != 0 && count[i] != i)
        return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.nextBeautifulNumber(1);
  return 0;
}
