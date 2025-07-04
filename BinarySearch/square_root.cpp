#include <iostream>
int square_root(int n) {
  int low = 0;
  int high = n;
  int mid;
  int ans = -1;
  while (low < high) {
    mid = (low + high) / 2;
    if ((mid * mid) == n) {
      return mid;
    } else if ((mid * mid) < n) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid;
  }
  return ans;
}
int main(int argc, char *argv[]) {
  std::cout << square_root(56);
  return 0;
}
