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
  ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *odd = head;
    ListNode *odd_head = head->next;
    ListNode *even = head->next;
    while (even && even->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    odd->next = odd_head;
    return head;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *new_list = s.oddEvenList(new ListNode(
      1, new ListNode(
             2, new ListNode(
                    3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
  while (new_list != nullptr) {
    cout << new_list->val;
    new_list = new_list->next;
  }
  return 0;
}
