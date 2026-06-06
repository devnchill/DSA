// 3751. Total Waviness of Numbers in Range I
// Solved
// Medium
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
//
//
//
// Constraints:
//
// 1 <= num1 <= num2 <= 105

#include <bits/stdc++.h>
using namespace std;

// METHOD 1
class Solution1 {
public:
  int totalWaviness(int num1, int num2) {
    int res = 0;
    for (int i = num1; i <= num2; i++) {
      string curr = to_string(i);
      if (curr.size() < 3)
        continue;
      for (size_t i = 1; i < curr.size() - 1; i++) {
        int p = curr[i - 1] - '0';
        int c = curr[i] - '0';
        int n = curr[i + 1] - '0';
        if ((c > p && c > n) || (c < p && c < n))
          res++;
      }
    }
    return res;
  }
};

// To practice digit dp
vector<vector<int>> dp(16, vector<int>(2, -1));
int solve(const string &num, int pos, bool is_tight) {
  if (pos == num.size())
    return 1;
  if (!is_tight && dp[pos][0] != -1)
    return dp[pos][is_tight];
  int ans = 0;
  int upper = is_tight ? num[pos] - '0' : 9;
  for (int digit = 0; digit <= upper; digit++) {
    bool tight = digit == upper && is_tight;
    ans += solve(num, pos + 1, tight);
  }
  if (!is_tight)
    dp[pos][0] = ans;
  return ans;
}

int main() { cout << solve("88", 0, true) << "\n"; }
