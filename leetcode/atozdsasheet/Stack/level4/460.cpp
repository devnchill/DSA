/*
460. LFU Cache
Hard
Topics
premium lock icon
Companies
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data
structure. int get(int key) Gets the value of the key if the key exists in the
cache. Otherwise, returns -1. void put(int key, int value) Update the value of
the key if present, or inserts the key if not already present. When the cache
reaches its capacity, it should invalidate and remove the least frequently used
key before inserting a new item. For this problem, when there is a tie (i.e.,
two or more keys with the same frequency), the least recently used key would be
invalidated. To determine the least frequently used key, a use counter is
maintained for each key in the cache. The key with the smallest use counter is
the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to
the put operation). The use counter for a key in the cache is incremented either
a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
"get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is
most recent) LFUCache lfu = new LFUCache(2); lfu.put(1, 1);   // cache=[1,_],
cnt(1)=1 lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1 lfu.get(1);      //
return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest,
invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3


Constraints:

1 <= capacity <= 104
0 <= key <= 105
0 <= value <= 109
At most 2 * 105 calls will be made to get and put.

*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int key;
  int value;
  int freq;
  Node *prev;
  Node *next;

  Node(int key, int value) {
    this->key = key;
    this->value = value;
    this->freq = 1;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    this->head = new Node(-1, -1);
    this->tail = new Node(-1, -1);
    this->head->next = this->tail;
    this->tail->prev = this->head;
  }

  void addFirst(Node *node) {
    node->prev = this->head;
    node->next = this->head->next;
    this->head->next->prev = node;
    this->head->next = node;
  }

  Node *remove(Node *node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
  }

  Node *removeLast() { return remove(this->tail->prev); }

  bool isEmpty() { return this->head->next == this->tail; }
};

class LFUCache {
public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    this->minFreq = 0;
  }
  int get(int key) {
    if (capacity == 0 || keyToNodeMap.find(key) == keyToNodeMap.end()) {
      return -1;
    }
    Node *node = keyToNodeMap[key];
    incrementFrequency(node);
    return node->value;
  }

  void put(int key, int value) {
    if (capacity == 0) {
      return;
    }

    if (keyToNodeMap.find(key) != keyToNodeMap.end()) {
      Node *node = keyToNodeMap[key];
      node->value = value;
      incrementFrequency(node);
      return;
    }

    if (keyToNodeMap.size() == capacity) {
      DoublyLinkedList *minFreqList = frequencyToListMap[minFreq];
      Node *nodeToEvict = minFreqList->removeLast();
      keyToNodeMap.erase(nodeToEvict->key);
      delete nodeToEvict; // Free memory
    }

    Node *newNode = new Node(key, value);
    addNodeToFrequencyList(newNode);
    keyToNodeMap[key] = newNode;
    minFreq = 1;
  }

private:
  int capacity;
  int minFreq;
  unordered_map<int, Node *> keyToNodeMap;
  unordered_map<int, DoublyLinkedList *> frequencyToListMap;

  void incrementFrequency(Node *node) {
    int currentFreq = node->freq;
    DoublyLinkedList *currentList = frequencyToListMap[currentFreq];

    currentList->remove(node);
    if (currentList->isEmpty()) {
      frequencyToListMap.erase(currentFreq);
      if (currentFreq == minFreq) {
        minFreq++;
      }
    }

    node->freq++;
    addNodeToFrequencyList(node);
  }

  void addNodeToFrequencyList(Node *node) {
    int freq = node->freq;

    if (frequencyToListMap.find(freq) == frequencyToListMap.end()) {
      frequencyToListMap[freq] = new DoublyLinkedList();
    }
    DoublyLinkedList *freqList = frequencyToListMap[freq];
    freqList->addFirst(node);
  }
};
