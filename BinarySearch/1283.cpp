/* Given an array of integers nums and an integer threshold, we will choose a
positive integer divisor, divide all the array by it, and sum the division's
result. Find the smallest divisor such that the result mentioned above is less
than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or
equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the
sum will be 5 (1+1+1+2).

Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44

Constraints:

    1 <= nums.length <= 5 * 104
    1 <= nums[i] <= 106
    nums.length <= threshold <= 106

*/
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int minDivisor = 1; // so sum would be sum of all elements
    int maxDivisor = *std::max_element(
        nums.begin(), nums.end()); // so sum would be same as length of array
    while (minDivisor < maxDivisor) {
      int currDivisor = (minDivisor + maxDivisor) / 2;
      if (findSum(currDivisor, nums) > threshold) {
        minDivisor = currDivisor + 1;
      } else {
        maxDivisor = currDivisor;
      }
    }
    return maxDivisor;
  }

private:
  int findSum(int divisor, vector<int> &nums) {
    int sum = 0;
    for (auto it : nums) {
      sum += (it + divisor - 1) / divisor;
    }
    return sum;
  }
};
