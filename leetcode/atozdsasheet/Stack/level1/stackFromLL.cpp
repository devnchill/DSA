/*
Implement stack using Linkedlist
0

100
Easy

Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The
implemented stack should support the following operations: push, pop, top, and
isEmpty.

Implement the LinkedListStack class:

void push(int x): Pushes element x onto the stack.

int pop(): Removes and returns the top element of the stack.

int top(): Returns the top element of the stack without removing it.

boolean isEmpty(): Returns true if the stack is empty, false otherwise.


Examples:
Input:

["LinkedListStack", "push", "push", "pop", "top", "isEmpty"]

[[], [3], [7], [], [], []]



Output: [null, null, null, 7, 3, false]

Explanation:

LinkedListStack stack = new LinkedListStack();

stack.push(3);

stack.push(7);

stack.pop(); // returns 7

stack.top(); // returns 3

stack.isEmpty(); // returns false

Input:

["LinkedListStack", "isEmpty"]

[[]]



Output: [null, true]

Explanation:

LinkedListStack stack = new LinkedListStack();

stack.isEmpty(); // returns true

Input:

["LinkedListStack", "push", "pop", "isEmpty"]

[[], [2], [], []]
*/
#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

class LinkedListStack {
private:
  class LinkedList {
  private:
    class Node {
    public:
      int val;
      Node *next;
      Node *prev;
      Node(int val) : val(val), next(nullptr), prev(nullptr) {};
      Node(int val, Node *next) : val(val), next(next), prev(nullptr) {};
    };
    Node *head;
    Node *tail;

  public:
    LinkedList() : head(nullptr), tail(nullptr) {};
    void push(int val) {
      Node *n = new Node(val);
      if (!this->head) {
        this->head = n;
        this->tail = n;
        return;
      }
      Node *prev = this->tail;
      this->tail = n;
      this->tail->prev = prev;
      prev->next = this->tail;
    }

    int pop() {
      if (!this->head)
        throw runtime_error("stack underflow");
      if (this->head && !this->head->next) {
        // remove head;
        Node *toBeDeleted = this->head;
        int ans = toBeDeleted->val;
        this->head = nullptr;
        this->tail = nullptr;
        delete toBeDeleted;
        return ans;
      }
      Node *toBeDeleted = this->tail;
      int ans = toBeDeleted->val;
      this->tail = this->tail->prev;
      this->tail->next = nullptr;
      delete toBeDeleted;
      return ans;
    }

    int top() { return this->tail->val; }
    bool isEmpty() { return head == nullptr; }
  };

public:
  LinkedList *ll;
  LinkedListStack() : ll(nullptr) {}

  void push(int x) {
    if (!ll) {
      ll = new LinkedList();
    }
    this->ll->push(x);
  }

  int pop() {
    if (!this->ll) {
      throw runtime_error("stack underflow");
    }
    return this->ll->pop();
  }

  int top() {
    if (!this->ll)
      throw runtime_error("stack underflow");
    return this->ll->top();
  }

  bool isEmpty() { return !ll || ll->isEmpty(); }
};

int main() {
  LinkedListStack *stack = new LinkedListStack();
  stack->push(2);
  stack->push(3);
  stack->push(4);
  stack->push(8);
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  return 0;
}
