
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *newHead = head->next;
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr && curr->next) {
      ListNode *nextNode = curr->next;
      ListNode *nextPair = nextNode->next;
      nextNode->next = curr;
      curr->next = nextPair;
      if (prev) {
        prev->next = nextNode;
      }
      prev = curr;
      curr = nextPair;
    }
    return newHead;
  }
};
