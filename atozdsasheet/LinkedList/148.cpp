/*Given the head of a linked list, return the list after sorting it in ascending
 * order.*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // Method 1. Brute Force
  ListNode *sortList(ListNode *head) {
    if (!head)
      return nullptr;
    ListNode *curr = head;
    vector<int> v;
    while (curr) {
      v.push_back(curr->val);
      curr = curr->next;
    }
    sort(v.begin(), v.end());
    ListNode *n = new ListNode(v[0]);
    ListNode *n_head = n;
    for (int i = 1; i < v.size(); i++) {
      n->next = new ListNode(v[i]);
      n = n->next;
    }
    return n_head;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *l = s.sortList(new ListNode(
      1, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(-8))))));
  while (l) {
    cout << l->val;
    l = l->next;
  }
  return 0;
}
