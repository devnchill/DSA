/*Topics
premium lock iconCompanies

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1)
      return list2;
    if (!list2)
      return list1;
    ListNode dummy;
    ListNode *tail = &dummy;
    while (list1 && list2) {
      if (list1->val >= list2->val) {
        tail->next = list2;
        list2 = list2->next;
      } else {
        tail->next = list1;
        list1 = list1->next;
      }
      tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy.next;
  }
};
