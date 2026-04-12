#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<double> internalAngles(vector<int> &sides) {
    int a = sides[0], b = sides[1], c = sides[2];
    if ((a + b <= c) || (b + c <= a) || (a + c <= b)) {
      return {};
    }
    double angle_a = acos((b * b + c * c - a * a) / (2.0 * b * c));
    double angle_b = acos((a * a + c * c - b * b) / (2.0 * a * c));
    double angle_c = acos((a * a + b * b - c * c) / (2.0 * a * b));
    angle_a = angle_a * 180 / M_PI;
    angle_b = angle_b * 180 / M_PI;
    angle_c = angle_c * 180 / M_PI;
    vector<double> angles = {angle_a, angle_b, angle_c};
    sort(angles.begin(), angles.end());
    return angles;
  }
};
