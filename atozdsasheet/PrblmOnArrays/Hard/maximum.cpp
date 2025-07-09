/*Given an integer array of size n, find all elements that appear more than ⌊
n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]

Example 2:

Input: nums = [1]
Output: [1]

Example 3:

Input: nums = [1,2]
Output: [1,2]

Constraints:

    1 <= nums.length <= 5 * 104
    -109 <= nums[i] <= 109

*/
#include <map>
#include <vector>
using std::pmr::vector;
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    std::pmr::map<int, int> m;
    int s = nums.size();
    vector<int> res;
    for (auto it : nums) {
      m[it]++;
      if (m[it] == int(s / 3) + 1) {
        res.push_back(it);
      }
      if (res.size() == 2)
        break;
    }
    return res;
  }
};
