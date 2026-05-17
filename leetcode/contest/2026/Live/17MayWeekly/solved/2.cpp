#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countKthRoots(int l, int r, int k) {
    long long left = ceil(pow(l, 1.0 / k));
    long long right = floor(pow(r, 1.0 / k));

    while (pow(left, k) < l)
      left++;
    while (left - 1 > 0 && pow(left - 1, k) >= l)
      left--;

    while (pow(right, k) > r)
      right--;
    while (pow(right + 1, k) <= r)
      right++;
    return max(0LL, right - left + 1);
  }
};
