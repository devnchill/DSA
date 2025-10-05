/*
17. Letter Combinations of a Phone Number
Medium
Topics
premium lock iconCompanies

Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                           {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                           {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> res;
    string curr;
    backtrack(digits, 0, curr, res, m);
    return res;
  }

private:
  void backtrack(string &digits, int index, string &curr, vector<string> &res,
                 map<char, string> &m) {
    if (index == digits.size()) {
      res.push_back(curr);
      return;
    }

    for (char c : m[digits[index]]) {
      curr.push_back(c);
      backtrack(digits, index + 1, curr, res, m);
      curr.pop_back();
    }
  }
};
