// sum of array elements
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int get_sum_of_array(vector<int> &arr, int i, int N) {
    if (i == N)
      return arr[i];
    return arr[i] + get_sum_of_array(arr, i + 1, N);
  }
};

int main() {
  Solution s;
  vector<int> arr = {1, 2, 3, 5, 6};
  cout << s.get_sum_of_array(arr, 0, arr.size() - 1) << "\n";
  return 0;
}
