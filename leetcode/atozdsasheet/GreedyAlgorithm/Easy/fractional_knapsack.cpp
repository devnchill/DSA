/*
Fractional Knapsack Problem : Greedy Approach

Problem Statement: The weight of N items and their corresponding values are
given. We have to put these items in a knapsack of weight W such that the total
value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight;
  int value;
};

double solve(vector<int> &value, vector<int> &weight, int capacity) {
  vector<Item> items;
  for (int i = 0; i < value.size(); i++) {
    items.push_back({weight[i], value[i]});
  }

  sort(items.begin(), items.end(), [](Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
  });

  double result = 0.0;

  for (int i = 0; i < items.size() && capacity > 0; i++) {
    if (items[i].weight <= capacity) {
      result += items[i].value;
      capacity -= items[i].weight;
    } else {
      result += (double)items[i].value * capacity / items[i].weight;
      capacity = 0;
    }
  }

  return result;
}

int main() {
  vector<int> values = {60, 100, 120};
  vector<int> weights = {10, 20, 30};
  cout << solve(values, weights, 50);
}
