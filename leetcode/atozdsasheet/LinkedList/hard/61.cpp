// Given the head of a linked list, rotate the list to the right by k places.

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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
      return head;
    ListNode *temp = head;
    int length = 1;
    // calc length
    while (temp->next != NULL) {
      ++length;
      temp = temp->next;
    }
    // point tail to head
    temp->next = head;
    // ensures 0<= k <=length
    k = k % length;
    int end = length - k;
    while (end--)
      temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
  }
};
