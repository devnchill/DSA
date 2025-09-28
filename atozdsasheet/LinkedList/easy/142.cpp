/*
* Given the head of a linked list, return the node where the cycle begins. If
there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the next pointer. Internally, pos is
used to denote the index of the node that tail's next pointer is connected to
(0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a
parameter.

Do not modify the linked list.*/

#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    int pos;
    set<ListNode *> visited_node;
    ListNode *temp_head = head;
    while (temp_head != nullptr) {
      auto it = visited_node.find(temp_head);
      if (it != visited_node.end()) {
        pos = distance(visited_node.begin(), it);
        for (int i = 0; i < pos; i++) {
          head = head->next;
        }
        return head;
      }
      visited_node.insert(temp_head);
      temp_head = temp_head->next;
    }
    return NULL;
  }
};

int main() {
  Solution s;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = head;
  cout << s.detectCycle(head)->val << endl;
  cout << s.detectCycle(head)->next;
  return 0;
}
