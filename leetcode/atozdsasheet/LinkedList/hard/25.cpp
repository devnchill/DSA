/*Given the head of a linked list, reverse the nodes of the list k at a time,
and return the modified list.

k is a positive integer and is less than or equal to the length of the linked
list. If the number of nodes is not a multiple of k then left-out nodes, in the
end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be
changed.*/

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
  struct ReversedBlock {
    ListNode *new_head;
    ListNode *new_tail;
    ListNode *next_node;
  };

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *new_head = nullptr;
    ListNode *prev_tail = nullptr;
    ListNode *curr = head;
    while (curr) {
      ListNode *temp = curr;
      int count = 0;
      for (; temp && count < k; count++)
        temp = temp->next;
      if (count < k)
        break;
      ReversedBlock block = reverse_k_nodes(curr, k);
      if (!new_head)
        new_head = block.new_head;
      if (prev_tail)
        prev_tail->next = block.new_head;
      prev_tail = block.new_tail;
      curr = block.next_node;
    }
    if (prev_tail)
      prev_tail->next = curr;

    return new_head ? new_head : head;
  }

private:
  ReversedBlock reverse_k_nodes(ListNode *head, int k) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next;
    for (int i = 0; i < k; i++) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return {prev, head, curr};
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *res = s.reverseKGroup(
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4)))), 3);
  while (res) {
    cout << res->val;
    res = res->next;
  }
  return 0;
}
