#include <set>
#include <vector>

class Solution {
public:
  // Method 1 . Using a set
  std::vector<int> unionArray(std::vector<int> &nums1,
                              std::vector<int> &nums2) {
    std::set<int> s;
    std::vector<int> union_arr;
    int i = 0;
    for (auto it : nums1)
      s.insert(it);

    for (auto it : nums2)
      s.insert(it);

    for (auto it : s)
      union_arr.push_back(it);

    return union_arr;
  }

  // Method 2. using 2 pointer
};
