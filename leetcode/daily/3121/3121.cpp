// 3121. Count the Number of Special Characters II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string word. A letter c is called special if it appears both
// in lowercase and uppercase in word, and every lowercase occurrence of c
// appears before the first uppercase occurrence of c.
//
// Return the number of special letters in word.
//
//
//
// Example 1:
//
// Input: word = "aaAbcBC"
//
// Output: 3
//
// Explanation:
//
// The special characters are 'a', 'b', and 'c'.
//
// Example 2:
//
// Input: word = "abc"
//
// Output: 0
//
// Explanation:
//
// There are no special characters in word.
//
// Example 3:
//
// Input: word = "AbBCab"
//
// Output: 0
//
// Explanation:
//
// There are no special characters in word.
//
//
//
// Constraints:
//
// 1 <= word.length <= 2 * 105
// word consists of only lowercase and uppercase English letters.

#include <bits/stdc++.h>
#include <cctype>
#include <climits>
using namespace std;

// METHOD 1
// class Solution {
// public:
//   int numberOfSpecialChars(string word) {
//     set<char> visited;
//     int res = 0;
//     int n = word.size();
//     set<char> uppercase_visited;
//     set<char> lowercase_visited;
//     for (int i = 0; i < n; i++) {
//       char curr = word[i];
//       bool found_lower = false;
//       if (isupper(curr)) {
//         if (uppercase_visited.find(curr) != uppercase_visited.end())
//           continue;
//         uppercase_visited.insert(curr);
//         if (lowercase_visited.find(tolower(curr)) == lowercase_visited.end())
//           continue;
//         for (int j = i + 1; j < n; j++) {
//           char next = word[j];
//           if (islower(next) && toupper(next) == curr) {
//             cout << "found lower for index: " << j << "\n";
//             found_lower = true;
//             break;
//           }
//         }
//         if (!found_lower) {
//           cout << "increasing res for index:" << i << "\n";
//           res++;
//         }
//       } else {
//         lowercase_visited.insert(curr);
//       }
//     }
//     return res;
//   }
// };

// METHOD 2
class Solution {
public:
  int numberOfSpecialChars(string word) {
    vector<int> last_lower_index(26, INT_MAX);
    vector<int> first_upper_index(26, INT_MAX);
    for (int i = 0; i < word.size(); i++) {
      char curr = word[i];
      if (islower(curr)) {
        last_lower_index[curr - 'a'] = i;
      } else {
        first_upper_index[curr - 'A'] = min(i, first_upper_index[curr - 'A']);
      }
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
      if (first_upper_index[i] == INT_MAX)
        continue;
      if (last_lower_index[i] < first_upper_index[i])
        res++;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.numberOfSpecialChars("AbcbDBdD") << "\n";
}
