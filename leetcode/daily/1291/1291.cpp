// 1291. Sequential Digits
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// An integer has sequential digits if and only if each digit in the number is
// one more than the previous digit.
//
// Return a sorted list of all the integers in the range [low, high] inclusive
// that have sequential digits.
//
//
//
// Example 1:
//
// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:
//
// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
//
//
// Constraints:
//
// 10 <= low <= high <= 10^9

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    string s = "123456789";
    vector<int> ans;
    int l = to_string(low).size();
    int h = to_string(high).size();
    for (int len = l; len <= h; len++) {
      for (int i = 0; i + len <= 9; i++) {
        int num = stoi(s.substr(i, len));
        if (num >= low && num <= high)
          ans.push_back(num);
      }
    }

    return ans;
  }
};
