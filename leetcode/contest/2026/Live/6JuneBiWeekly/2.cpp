#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int get_min_illumination(int brightness, int n) {
    return (brightness + 2) / 3;
  }

public:
  long long minEnergy(int n, int brightness, vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (auto &curr : intervals) {
      if (merged.empty() || merged.back()[1] < curr[0]) {
        merged.push_back(curr);
      } else {
        merged.back()[1] = max(merged.back()[1], curr[1]);
      }
    }
    long long res = 0;
    for (auto &curr : merged) {
      int start = curr[0], end = curr[1];
      int duration = end - start + 1;
      int illumination = get_min_illumination(brightness, n);
      res += 1LL * duration * illumination;
    }
    return res;
  }
};
