// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *fast = dummy;
    ListNode *slow = dummy;
    int i = 0;
    while (i < n) {
      fast = fast->next;
      i++;
    }
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *h = s.removeNthFromEnd(
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4)))), 3);
  while (h) {
    cout << h->val;
    h = h->next;
  }

  return 0;
}
