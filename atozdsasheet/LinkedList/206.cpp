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
  ListNode *reverseList(ListNode *head) {
    // // METHOD 1
    // ListNode *prev = nullptr;
    // ListNode *curr = head;
    // ListNode *next;
    // while (curr != nullptr) {
    //   next = curr->next;
    //   curr->next = prev;
    //   prev = curr;
    //   curr = next;
    // }
    // head = prev;
    // return prev;
    if (!head || !head->next)
      return head;
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *n1 =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  ListNode *head = s.reverseList(n1);
  for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
    std::cout << curr->val << " ";
  }
  std::cout << std::endl;
  return 0;
}
