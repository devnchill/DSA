// 1306. Jump Game III
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of non-negative integers arr, you are initially positioned at
// start index of the array. When you are at index i, you can jump to i + arr[i]
// or i - arr[i], check if you can reach any index with value 0.
//
// Notice that you can not jump outside of the array at any time.
//
//
//
// Example 1:
//
// Input: arr = [4,2,3,0,3,1,2], start = 5
// Output: true
// Explanation:
// All possible ways to reach at index 3 with value 0 are:
// index 5 -> index 4 -> index 1 -> index 3
// index 5 -> index 6 -> index 4 -> index 1 -> index 3
// Example 2:
//
// Input: arr = [4,2,3,0,3,1,2], start = 0
// Output: true
// Explanation:
// One possible way to reach at index 3 with value 0 is:
// index 0 -> index 4 -> index 1 -> index 3
// Example 3:
//
// Input: arr = [3,0,2,1,2], start = 2
// Output: false
// Explanation: There is no way to reach at index 1 with value 0.
//
//
// Constraints:
//
// 1 <= arr.length <= 5 * 104
// 0 <= arr[i] < arr.length
// 0 <= start < arr.length

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> visited;
  bool check(vector<int> &arr, int curr_index) {
    while (visited[curr_index] != 1) {
      if (arr[curr_index] == 0)
        return true;
      visited[curr_index] = 1;
      int high = curr_index + arr[curr_index];
      int low = curr_index - arr[curr_index];
      bool low_res = false, high_res = false;
      if (high < arr.size() && high >= 0)
        high_res = check(arr, high);
      if (low < arr.size() && low >= 0)
        low_res = check(arr, low);
      return low_res || high_res;
    }
    return false;
  }

public:
  bool canReach(vector<int> &arr, int start) {
    int low = 0, high = arr.size() - 1;
    visited.resize(high + 1, 0);
    return check(arr, start);
  }
};

int main() {
  Solution s;
  vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
  cout << s.canReach(arr, 5);
}
