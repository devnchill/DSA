// replace a with x
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string replace(string s, int i, int N) {
    if (i == N)
      return s;
    if (s[i] == 'a')
      s[i] = 'x';
    return replace(s, i + 1, N);
  }
};

int main() {
  Solution s;
  string st = "Amax";
  cout << s.replace(st, 0, st.size()) << "\n";
  return 0;
}
