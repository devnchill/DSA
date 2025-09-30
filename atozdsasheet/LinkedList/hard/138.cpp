/*
A linked list of length n is given such that each node contains an additional
random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n
brand new nodes, where each new node has its value set to the value of its
corresponding original node. Both the next and random pointer of the new nodes
should point to new nodes in the copied list such that the pointers in the
original list and copied list represent the same list state. None of the
pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random
--> Y, then for the corresponding two nodes x and y in the copied list, x.random
--> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each
node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) that the random
pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.

*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    // modify list to include the copied list adjacent to original list
    Node *temp = head;
    while (temp) {
      Node *next = temp->next;
      temp->next = new Node(temp->val);
      temp->next->next = next;
      temp = temp->next->next;
    }
    // now set random pointer
    temp = head;
    while (temp && temp->next) {
      if (!temp->random) {
        temp->next->random = nullptr;
      } else {
        temp->next->random = temp->random->next;
      }
      temp = temp->next->next;
    }
    Node *orig = head;
    Node *copied = head->next;
    Node *orig_ptr = orig;
    Node *copied_ptr = copied;
    while (orig_ptr && orig_ptr->next) {
      orig_ptr->next = orig_ptr->next->next;
      if (copied_ptr->next) {
        copied_ptr->next = copied_ptr->next->next;
      }
      orig_ptr = orig_ptr->next;
      copied_ptr = copied_ptr->next;
    }
    return copied;
  }
};

int main() {
  Solution s;
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  Node *new_node = s.copyRandomList(n1);
  while (new_node) {
    cout << new_node->val;
    new_node = new_node->next;
  }
  return 0;
}
