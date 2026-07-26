// 3499. Maximize Active Section with Trade I
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a binary string s of length n, where:
//
// '1' represents an active section.
// '0' represents an inactive section.
// You can perform at most one trade to maximize the number of active sections
// in s. In a trade, you:
//
// Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
// Afterward, convert a contiguous block of '0's that is surrounded by '1's to
// all '1's. Return the maximum number of active sections in s after making the
// optimal trade.
//
// Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1'
// + s + '1'. The augmented '1's do not contribute to the final count.
//
//
//
// Example 1:
//
// Input: s = "01"
//
// Output: 1
//
// Explanation:
//
// Because there is no block of '1's surrounded by '0's, no valid trade is
// possible. The maximum number of active sections is 1.
//
// Example 2:
//
// Input: s = "0100"
//
// Output: 4
//
// Explanation:
//
// String "0100" → Augmented to "101001".
// Choose "0100", convert "101001" → "100001" → "111111".
// The final string without augmentation is "1111". The maximum number of active
// sections is 4. Example 3:
//
// Input: s = "1000100"
//
// Output: 7
//
// Explanation:
//
// String "1000100" → Augmented to "110001001".
// Choose "000100", convert "110001001" → "110000001" → "111111111".
// The final string without augmentation is "1111111". The maximum number of
// active sections is 7. Example 4:
//
// Input: s = "01010"
//
// Output: 4
//
// Explanation:
//
// String "01010" → Augmented to "1010101".
// Choose "010", convert "1010101" → "1000101" → "1111101".
// The final string without augmentation is "11110". The maximum number of
// active sections is 4.
//
//
// Constraints:
//
// 1 <= n == s.length <= 105
// s[i] is either '0' or '1'

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    vector<pair<int, int>> start_end_of_ones;
    pair<int, int> curr;
    int ones = count(s.begin(), s.end(), '1');
    for (int i = 0; i < s.size(); i++) {
      int l = 0, r = 0;
      if (s[i] == '1') {
        l = i;
        while (i < s.size() && s[i] == '1')
          i++;
        r = i - 1;
        bool leftZero = (l > 0 && s[l - 1] == '0');
        bool rightZero = (i < s.size() && s[i] == '0');
        if (leftZero && rightZero)
          start_end_of_ones.push_back({l, r});
      }
    }
    int res = 0;
    for (auto &[st, en] : start_end_of_ones) {
      int idx = st - 1;
      int bef = 0;
      while (idx >= 0 && s[idx] == '0') {
        idx--;
        bef++;
      }
      idx = en + 1;
      int aft = 0;
      while (idx < s.size() && s[idx] == '0') {
        idx++;
        aft++;
      }
      res = max(res, bef + aft);
    }
    return ones + res;
  }
};

int main() {
  Solution s;
  cout << s.maxActiveSectionsAfterTrade("1000100") << "\n";
}
