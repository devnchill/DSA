#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
  unordered_map<int, int> m;
  vector<int> a;

public:
  RandomizedSet() {}

  bool insert(int val) {
    if (m.find(val) != m.end()) {
      return false;
    }
    m[val] = a.size();
    a.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (m.find(val) != m.end()) {
      a[m[val]] = a.back();
      m[a.back()] = m[val];
      m.erase(val);
      a.pop_back();
      return true;
    }
    return false;
  }

  int getRandom() { return a[rand() % a.size()]; }
};
