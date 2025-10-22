/*
Implement Queue using Arrays
0
100
Easy

Implement a First-In-First-Out (FIFO) queue using an array. The implemented
queue should support the following operations: push, dequeue, pop, and isEmpty.

Implement the ArrayQueue class:

void push(int x): Adds element x to the end of the queue.

int pop(): Removes and returns the front element of the queue.

int peek(): Returns the front element of the queue without removing it.

boolean isEmpty(): Returns true if the queue is empty, false otherwise.

Examples:
Input:

["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]

[[], [5], [10], [], [], []]

Output: [null, null, null, 5, 5, false]

Explanation:

ArrayQueue queue = new ArrayQueue();

queue.push(5);

queue.push(10);

queue.peek(); // returns 5

queue.pop(); // returns 5

queue.isEmpty(); // returns false
*/
#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
  queue<int> q;
  MyStack() {}

  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int ans = q.front();
    q.pop();
    return ans;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};
