/*
* Koko loves to eat bananas. There are n piles of bananas, the ith pile has
piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses
some pile of bananas and eats k bananas from that pile. If the pile has less
than k bananas, she eats all of them instead and will not eat any more bananas
during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before
the guards return.

Return the minimum integer k such that she can eat all the bananas within h
hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

Constraints:

    1 <= piles.length <= 104
    piles.length <= h <= 109
    1 <= piles[i] <= 109

*/

#include <algorithm>
#include <vector>
using std::vector;
class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1;
    int high = *std::max_element(piles.begin(), piles.end());
    int mid;
    int ans = -1;
    while (low <= high) {
      mid = low + (high - low) / 2;
      int time_for_mid = calcTime(piles, mid);
      if (time_for_mid > h) {
        // we are eating too slow. we need to increament our speed
        low = mid + 1;
      } else {
        // we are eating fast
        ans = mid;
        high = mid - 1;
      }
    }
    return ans;
  }

private:
  int calcTime(vector<int> &piles, int k) {
    int hr = 0;
    for (auto it : piles) {
      hr += (it + k - 1) / k;
    }
    return hr;
  }
};

#include <iostream>

int main() {
  Solution s;
  vector<int> piles = {3, 6, 7, 11};
  std::cout << s.minEatingSpeed(piles, 8);
  return 0;
}
