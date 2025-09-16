#include <bits/stdc++.h>
using std::string;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string res = "";
    int i = 0;
    int j = 0;
    int size1 = word1.size();
    int size2 = word2.size();
    while (i < size1 && j < size2) {
      res.push_back(word1[i]);
      res.push_back(word2[j]);
      i++;
      j++;
    }
    if (size1 > size2) {
      while (i < size1) {
        res.push_back(word1[i]);
        i++;
      }
    } else if (size2 > size1) {
      while (j < size2) {
        res.push_back(word2[j]);
        j++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.mergeAlternately("hello", "world");
  return 0;
}
