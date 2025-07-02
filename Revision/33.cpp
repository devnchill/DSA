#include <iostream>
#include <vector>
using std::pmr::vector;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int size = nums.size();
    int low = 0;
    int high = size - 1;
    int mid = -1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[low] < nums[mid]) {
        if (target > nums[low] && target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (target > nums[mid] && target < nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  std::cout << s.search(nums, 0);
}
