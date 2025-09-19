/*
 * Topics
premium lock iconCompanies

Given the head of a singly linked list, return the middle node of the linked
list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return
the second one.

Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100

 Topics
premium lock iconCompanies

Given the head of a singly linked list, return the middle node of the linked
list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return
the second one.

Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100

 Topics
premium lock iconCompanies

Given the head of a singly linked list, return the middle node of the linked
list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return
the second one.

Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100

 Topics
premium lock iconCompanies

Given the head of a singly linked list, return the middle node of the linked
list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return
the second one.

Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100

 Given the head of a singly linked list, return the middle node of the linked
list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return
the second one.

Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100
*/

/**
 * Definition for singly-linked list.
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
  //   // METHOD 1 BRUTEFORCE
  //   ListNode *middleNode(ListNode *head) {
  //     // find length of linked list
  //     int count = 0;
  //     ListNode *curr_node = head;
  //     while (curr_node != nullptr) {
  //       count++;
  //       curr_node = curr_node->next;
  //     }
  //     // get (count/2 + 1) middle node for odd nodes and (count/2) , (count/2
  //     + 1)
  //     // for even terms
  //     for (int i = 0; i < count / 2; i++) {
  //       head = head->next;
  //     }
  //     return head;
  //   }
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *n3 = new ListNode(5);
  ListNode *n2 = new ListNode(4, n3);
  ListNode *n1 = new ListNode(3, n2);
  ListNode *n0 = new ListNode(2, n1);
  ListNode *head = new ListNode(1, n0);

  ListNode *mid = s.middleNode(head);
  std::cout << mid->val << "\n";
  return 0;
}
