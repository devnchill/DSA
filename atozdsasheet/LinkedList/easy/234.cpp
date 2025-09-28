/* Given the head of a singly linked list, return true if it is a planidrme or
false otherwise. */

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
  bool isPalindrome(ListNode *head) {
    // METHOD1
    // reverse linked list and store it .
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    while (prev != nullptr) {
      if (head->val == prev->val) {
        head = head->next;
        prev = prev->next;
        continue;
      }
      return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome(
      new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1)))));
  return 0;
}
