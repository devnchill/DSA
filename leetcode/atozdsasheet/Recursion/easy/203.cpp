/*
203. Remove Linked List Elements
Easy
Topics
premium lock iconCompanies

Given the head of a linked list and an integer val, remove all the nodes of the
linked list that has Node.val == val, and return the new head.



Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []



Constraints:

    The number of nodes in the list is in the range [0, 104].
    1 <= Node.val <= 50
    0 <= val <= 50

*/
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
  ListNode *removeElements(ListNode *head, int val) {
    if (!head)
      return nullptr;
    head->next = removeElements(head->next, val);
    if (head->val == val)
      return head->next;
    return head;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  ListNode *head = new ListNode(
      2, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(2)))));
  head = s.removeElements(head, 2);
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }
  return 0;
}
