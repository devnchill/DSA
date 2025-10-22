/*
Implement Stack using Arrays
0
100
Easy

Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack
should support the following operations: push, pop, peek, and isEmpty.

Implement the ArrayStack class:

void push(int x): Pushes element x onto the stack.

int pop(): Removes and returns the top element of the stack.

int top(): Returns the top element of the stack without removing it.

boolean isEmpty(): Returns true if the stack is empty, false otherwise.


Please note that this section might seem a bit difficult without prior knowledge
on what stacks is, we will soon try to add basics concepts for your ease! If you
know the concepts already please go ahead to give a shot to the problem. Cheers!


Examples:
Input: ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]

[[], [5], [10], [], [], []]

Output: [null, null, null, 10, 10, false]

Explanation:

ArrayStack stack = new ArrayStack();

stack.push(5);

stack.push(10);

stack.top(); // returns 10

stack.pop(); // returns 10

stack.isEmpty(); // returns false
*/
#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
public:
  vector<int> stack;

  void push(int x) { stack.push_back(x); }

  int pop() {
    int ans = stack.back();
    stack.pop_back();
    return ans;
  }

  int top() { return stack.back(); }

  bool isEmpty() { return stack.empty(); }
};
