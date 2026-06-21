#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDistance(string moves) {
    int dash = 0;
    pair<int, int> coord;
    for (char ch : moves) {
      switch (ch) {
      case 'L': {
        coord.first--;
        break;
      }
      case 'R': {
        coord.first++;
        break;
      }
      case 'U': {
        coord.second++;
        break;
      }
      case 'D': {
        coord.second--;
        break;
      }
      default: {
        dash++;
      };
      }
    }
    return abs(coord.first) + abs(coord.second) + dash;
  }
};

int main() {
  Solution s;
  cout << s.maxDistance("U_L") << "\n";
}
