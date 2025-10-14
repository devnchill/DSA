/*
* Given head, the head of a linked list, determine if the linked list has a
cycle in it.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the next pointer. Internally, pos is
used to denote the index of the node that tail's next pointer is connected to.
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 */

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    set<ListNode *> visited_node;
    while (head != nullptr) {
      if (visited_node.find(head) != visited_node.end())
        return true;
      visited_node.insert(head);
      head = head->next;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *head = new ListNode(1);
  cout << s.hasCycle(head);
  return 0;
}
