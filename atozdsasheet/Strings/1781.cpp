/*
* 1781. Sum of Beauty of All Substrings
Medium
Topics
premium lock iconCompanies
Hint

The beauty of a string is the difference in frequencies between the most
frequent and least frequent characters.

    For example, the beauty of "abaacc" is 3 - 1 = 2.

Given a string s, return the sum of beauty of all of its substrings.

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are
["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Example 2:

Input: s = "aabcbaa"
Output: 17

Constraints:

    1 <= s.length <= 500
    s consists of only lowercase English letters.

*/
#include <climits>
#include <iostream>
#include <map>
#include <string>
using std::string;
class Solution {
public:
  // METHOD 1. BRUTE FORCE
  // int beautySum(string s) {
  //   int len = s.size();
  //   int beauty = 0;
  //   for (int i = 0; i < len; i++) {
  //     string temp;
  //     for (int j = i; j < len; j++) {
  //       temp.push_back(s[j]);
  //       beauty += calculateBeautyValue(temp);
  //     }
  //   }
  //   return beauty;
  // }

  // METHOD 2. Use the loop for generating substring as loop for counting
  // frequency.
  int beautySum(string s) {
    int len = s.size();
    int beauty = 0;
    for (int i = 0; i < len; i++) {
      int arr[26] = {0};
      for (int j = i; j < len; j++) {
        arr[s[j] - 'a']++;
        int max = INT_MIN;
        int min = INT_MAX;
        for (int k = 0; k < 26; k++) {
          if (arr[k] > max)
            max = arr[k];
          if (arr[k] < min && arr[k] != 0)
            min = arr[k];
        }
        beauty += (max - min);
      }
    }
    return beauty;
  }

private:
  int calculateBeautyValue(string s) {
    std::map<char, int> m;
    int maxFreq = INT_MIN;
    int minFreq = INT_MAX;
    for (auto it : s) {
      m[it]++;
    }
    for (auto it : m) {
      if ((it.second) > maxFreq)
        maxFreq = it.second;
      if ((it.second) < minFreq)
        minFreq = it.second;
    }
    return maxFreq - minFreq;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.beautySum("aabcbaa");
  return 0;
}
