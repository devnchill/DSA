#include <cmath>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> divisors(int n) {
    set<int> divisors_set;
    for (int i = 1; i <= sqrt(n); i++) {
      if (n % i == 0) {
        divisors_set.insert(i);
        divisors_set.insert(n / i);
      }
    }
    return vector<int>(divisors_set.begin(), divisors_set.end());
  }
};
