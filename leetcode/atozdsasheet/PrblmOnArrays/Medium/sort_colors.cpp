#include <vector>
class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    int zero = 0, one = 0, two = 0;
    for (auto it : nums) {
      switch (it) {
      case 0:
        zero++;
        break;
      case 1:
        one++;
        break;
      case 2:
        two++;
        break;
      }
    }

    int index = 0;
    for (int i = 0; i < zero; ++i)
      nums[index++] = 0;
    for (int i = 0; i < one; ++i)
      nums[index++] = 1;
    for (int i = 0; i < two; ++i)
      nums[index++] = 2;
  }
};
