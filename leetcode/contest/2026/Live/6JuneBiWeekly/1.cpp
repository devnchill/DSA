#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  string get_binary(int n) {
    string res;
    while (n > 0) {
      res.push_back(n % 2 == 0 ? '0' : '1');
      n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
  }

public:
  bool consecutiveSetBits(int n) {
    string b = get_binary(n);
    if (b.size() < 2)
      return false;
    int freq = 0;
    cout << b << "\n";
    for (size_t i = 0; i < b.size() - 1; i++) {
      if (b[i] == b[i + 1] && b[i] == '1')
        freq++;
    }
    if (freq == 1)
      return true;
    return false;
  }
};
