/*2. Add Two Numbers
Medium
Topics
premium lock iconCompanies

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.*/

#include <bits/stdc++.h>
#include <iostream>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode(0); // dummy head
    ListNode *curr = res;
    int borrow = 0;
    while (l1 || l2) {
      int x = (l1 ? l1->val : 0);
      int y = (l2 ? l2->val : 0);
      int sum = x + y + borrow;
      borrow = sum / 10;
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    if (borrow) {
      curr->next = new ListNode(borrow);
    }
    return res->next;
  }
};
;

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *res =
      s.addTwoNumbers(new ListNode(1, new ListNode(2, new ListNode(3))),
                      new ListNode(1, new ListNode(2, new ListNode(3))));
  while (res) {
    cout << res->val;
    res = res->next;
  }
  return 0;
}
