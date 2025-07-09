#include <iostream>
#include <vector>
int main(int argc, char *argv[]) {
  std::pmr::vector<int> nums = {4, 5, -5, 0, 1, 2, 3};
  int size = nums.size();
  int low = 0;
  int high = size - 1;
  int mid;
  while (low < high) {
    mid = low + (high - low) / 2;
    if (nums[high] < nums[mid]) {
      // minimum element lies in right sorted array?
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  std::cout << nums[low];
  return 0;
}
