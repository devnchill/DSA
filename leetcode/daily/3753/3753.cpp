// 3753. Total Waviness of Numbers in Range II
// Attempted
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given two integers num1 and num2 representing an inclusive range
// [num1, num2].
//
// The waviness of a number is defined as the total count of its peaks and
// valleys:
//
// A digit is a peak if it is strictly greater than both of its immediate
// neighbors. A digit is a valley if it is strictly less than both of its
// immediate neighbors. The first and last digits of a number cannot be peaks or
// valleys. Any number with fewer than 3 digits has a waviness of 0. Return the
// total sum of waviness for all numbers in the range [num1, num2].
//
//
// Example 1:
//
// Input: num1 = 120, num2 = 130
//
// Output: 3
//
// Explanation:
//
// In the range [120, 130]:
//
// 120: middle digit 2 is a peak, waviness = 1.
// 121: middle digit 2 is a peak, waviness = 1.
// 130: middle digit 3 is a peak, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.
//
// Example 2:
//
// Input: num1 = 198, num2 = 202
//
// Output: 3
//
// Explanation:
//
// In the range [198, 202]:
//
// 198: middle digit 9 is a peak, waviness = 1.
// 201: middle digit 0 is a valley, waviness = 1.
// 202: middle digit 0 is a valley, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.
//
// Example 3:
//
// Input: num1 = 4848, num2 = 4848
//
// Output: 2
//
// Explanation:
//
// Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley,
// giving a waviness of 2.

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
  using ll = long long;

  struct Res {
    ll count;
    ll total_waviness;
  };

  struct Key {
    int pos;
    int prev2;
    int prev1;
    bool leading;
    bool tight;

    bool operator==(Key const &o) const {
      return pos == o.pos && prev2 == o.prev2 && prev1 == o.prev1 &&
             leading == o.leading && tight == o.tight;
    }
  };

  struct KeyHash {
    size_t operator()(Key const &k) const {
      return (((((k.pos * 31 + k.prev2) * 31 + k.prev1) * 2 + k.leading) * 2) +
              k.tight);
    }
  };

  string s;
  unordered_map<Key, Res, KeyHash> memo;

  Res dfs(int pos, int prev2, int prev1, bool leading, bool tight) {
    if (pos == (int)s.size()) {
      return {1, 0};
    }

    Key key{pos, prev2, prev1, leading, tight};
    if (!tight && memo.count(key))
      return memo[key];

    int upper = tight ? (s[pos] - '0') : 9;

    Res res{0, 0};

    for (int d = 0; d <= upper; d++) {
      bool next_tight = tight && (d == upper);
      bool next_leading = leading && (d == 0);

      int nprev2 = prev2, nprev1 = prev1;

      if (!next_leading) {
        nprev2 = prev1;
        nprev1 = d;
      }

      int add = 0;

      if (!next_leading && prev2 != -1 && prev1 != -1) {
        if ((prev1 > d && prev1 > prev2) || (prev1 < d && prev1 < prev2)) {
          add = 1;
        }
      }

      Res child = dfs(pos + 1, nprev2, nprev1, next_leading, next_tight);

      res.total_waviness += child.total_waviness + child.count * add;
      res.count += child.count;
    }

    if (!tight)
      memo[key] = res;
    return res;
  }

public:
  long long totalWaviness(long long num1, long long num2) {
    s = to_string(num2);
    memo.clear();
    ll r = dfs(0, -1, -1, true, true).total_waviness;

    s = to_string(num1 - 1);
    memo.clear();
    ll l = dfs(0, -1, -1, true, true).total_waviness;

    return r - l;
  }
};
