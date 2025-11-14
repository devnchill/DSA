/*
Implement Min Heap

0

100
Medium

You need to implement the Min Heap with the following given methods.

insert (x) -> insert value x to the min heap
getMin -> Output the minimum value from min heap
exctractMin -> Remove the minimum element from the heap
heapSize -> return the current size of the heap
isEmpty -> returns if heap is empty or not
changeKey (ind, val) -> update the value at given index to val (index will be
given 0-based indexing) initializeHeap -> Initialize the heap

Examples:
Input : operation = [ "initializeheap", "insert", "insert", "insert", "getMin",
"heapSize", "isEmpty", "extractMin", "changeKey" , "getMin" ]

nums = [ [4], [1], [10], [0, 16] ]

Output : [ null, null, null, null, 1, 3, 0, null, null, 10 ]

Explanation : In 1st operation we initialize the heap to empty heap.

In 2nd, 3rd, 4th operation we insert 4, 1, 10 to the heap respectively. The heap
after 4th operation will be -> [1, 4, 10].

In 5th operation we output the minimum element from the heap i.e. 1.

In 6th operation we output the size of the current heap i.e. 3.

In 7th operation we output whether the heap is empty or not i.e. false (0).

In 8th operation we remove the minimum element from heap. So the ne heap becomes
-> [4, 10].

In 9th operation we change the 0th index element to 16. So new heap becomes ->
[16, 10]. After heapify -> [10, 16].

In 10th operation we output the minimum element of the heap i.e. 10.

Input : operation = [ "initializeheap", "insert", "insert", "extractMin",
"getMin", "insert", "heapSize", "isEmpty", "extractMin", "changeKey" , "getMin"
]

nums = [ [4], [1], [1], [0, 2] ]

Output : [ null, null, null, null, 4, null, 2, 0, null, null, 2 ]

Explanation : In 1st operation we initialize the heap to empty heap.

In 2nd, 3rd operation we insert 4, 1 to the heap respectively. The heap after
4th operation will be -> [1, 4].

In 4th operation we remove the minimum element from heap. So the ne heap becomes
-> [4].

In 5th operation we output the minimum element of the heap i.e. 4.

In 6th operation we operation we insert 1 to the heap. The heap after 6th
operation will be -> [1, 4].

In 7th operation we output the size of the current heap i.e. 2.

In 8th operation we output whether the heap is empty or not i.e. false (0).

In 9th operation we remove the minimum element from heap. So the ne heap becomes
-> [4].

In 10th operation we change the 0th index element to 2. So new heap becomes ->
[2].

In 11th operation we output the minimum element of the heap i.e. 2.

Constraints:
1 <= n <= 105
-105 <= nums[i] <= 105

*/
#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

class MinHeap {
  int capacity, size;
  int *heap;

public:
  MinHeap(int cap) : capacity(cap), size(0), heap(new int[cap]) {};
  void insert(int x) {
    if (size == capacity) {
      cerr << "Heap Overflow\n";
      return;
    }
    heap[size] = x;
    int i = size;
    size++;
    while (i > 0) {
      int parent = (i - 1) / 2;
      if (heap[parent] <= heap[i])
        break;
      int temp = heap[parent];
      heap[parent] = heap[i];
      heap[i] = temp;
      i = parent;
    }
  }

  int getMin() const { return heap[0]; }

  int heapSize() const { return size; }

  bool isEmpty() const { return size == 0; }

  // question assumes that value would be more than its parent so no need to
  // heapify
  void changeKey(int index, int new_val) { heap[index] = new_val; }

  int extractMin() {
    if (size == 0)
      throw std::runtime_error("Heap Underflow");
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
  }

  void heapifyDown(int i) {
    while (true) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int smallest = i;

      if (left < size && heap[left] < heap[smallest])
        smallest = left;

      if (right < size && heap[right] < heap[smallest])
        smallest = right;

      if (smallest == i)
        break;

      swap(heap[i], heap[smallest]);
      i = smallest;
    }
  }
};

int main(int argc, char *argv[]) {
  MinHeap heap(20);
  cout << heap.heapSize() << "\n";
  heap.insert(1);
  cout << heap.getMin();
  return 0;
}
