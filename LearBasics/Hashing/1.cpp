/*
Given an array of n integers, find the most frequent element in it i.e., the
element that occurs the maximum number of times. If there are multiple elements
that appear a maximum number of times, find the smallest of them. Please note
that this section might seem a bit difficult without prior knowledge on what
hashing is, we will soon try to add basics concepts for your ease! If you know
the concepts already please go ahead to give a shot to the problem. Cheers!
*/

//----------------------------------------------Solution--------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mostFrequentElement(vector<int> &nums) {
    size_t length = nums.size();
    unordered_map<int, int> freq;
    for (size_t i = 0; i < length; i++) {
      freq[nums[i]]++;
    }
    int maxFreq = 0;
    int result = INT_MAX;
    for (const auto &entry : freq) {
      int element = entry.first;
      int count = entry.second;
      if (count > maxFreq || (count == maxFreq && element < result)) {
        maxFreq = count;
        result = element;
      }
    }
    return result;
  }
};
