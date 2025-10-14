#include <map>
#include <vector>
class Solution {
public:
  int singleNumber1(std::vector<int> &nums) {
    std::map<long long, int> m;
    for (auto it : nums) {
      m[it]++;
    }
    for (auto &pair : m) {
      if (pair.second == 1)
        return pair.first;
    }
    return -1;
  }

  int singleNumber2(std::vector<int> &nums) {
    int xorr = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      xorr = xorr ^ nums[i];
    }
    return xorr;
  };
};
