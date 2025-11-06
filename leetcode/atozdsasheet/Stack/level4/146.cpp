/*
146. LRU Cache
Medium
Topics
premium lock icon
Companies
Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return
-1. void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache. If the number of keys exceeds
the capacity from this operation, evict the least recently used key. The
functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
  class Node {
  public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val)
        : key(key), val(val), next(nullptr), prev(nullptr) {};
  };
  Node *head = new Node(-1, -1);
  Node *tail = new Node(-1, -1);

  int capacity;
  unordered_map<int, Node *> m;

  void detach(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveNextToHead(Node *node) {
    Node *temp = head->next;
    head->next = node;
    node->prev = head;
    node->next = temp;
    temp->prev = node;
  }

  void deleteLeastRecent() {
    Node *node = tail->prev;
    detach(node);
    m.erase(node->key);
    delete node;
  }

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    auto it = m.find(key);
    if (it != m.end()) {
      Node *node = it->second;
      detach(node);
      moveNextToHead(node);
      return node->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (m.find(key) != m.end()) {
      Node *node = m[key];
      node->val = value;
      detach(node);
      moveNextToHead(node);
      return;
    }
    if (m.size() >= capacity)
      deleteLeastRecent();
    Node *newNode = new Node(key, value);
    m[key] = newNode;
    moveNextToHead(newNode);
  }
};

int main() {
  LRUCache *l = new LRUCache(4);
  l->put(1, 1);
  l->put(2, 2);
  l->put(3, 3);
  l->put(4, 4);
  l->put(6, 6);
  cout << l->get(1);
  cout << l->get(2);
  cout << l->get(3);
  cout << l->get(4);
  cout << l->get(2);
  cout << l->get(1);
  cout << l->get(3);
  return 0;
}
