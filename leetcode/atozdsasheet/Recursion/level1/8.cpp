// check if array is sorted or not
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool is_sorted_arr(vector<int> &arr, int i, int end) {
    if (i == end)
      return true;
    if (arr[i] > arr[i + 1])
      return false;
    return is_sorted_arr(arr, i + 1, end);
  }
};
int main() {
  Solution s;
  vector<int> arr = {1, 2, 2, 2, 8, 9};
  cout << s.is_sorted_arr(arr, 0, arr.size() - 1);
  return 0;
}
