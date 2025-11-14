/*
Implement Max Heap
    0
    100 Medium
        You need to implement the Max Heap with the following given methods
    insert(x)
            ->insert value x to the max heap getMax
            ->Output the maximum value from the max heap
    exctractMax->Remove the maximum element from the heap heapSize
            ->return the current size of the heap isEmpty->returns
    if heap is empty
    or not changeKey(ind, val)
               ->update the value at given index to
           val(index will be given 0 -
               based indexing) initializeHeap->Initialize the heap

           Examples : Input
    : operation =
    [
      "initializeHeap", "insert", "insert", "insert", "getMax", "heapSize",
      "isEmpty", "exctractMax", "changeKey", "getMax"
    ]

    nums = [ [4], [1], [10], [ 0, 16 ] ]

           Output : [ null, null, null, null, 10, 3, 0, null, null, 16 ]

                    Explanation :

    In 1st operation we initialize the heap to empty heap.

    In 2nd,
      3rd, 4th operation we insert 4, 1,
      10 to the heap respectively.The heap after
          4th operation will be->[10, 4, 1]
              .

          In 5th operation we output the maximum element from the heap i.e
              .10.

          In 6th operation we output the size of the current heap i.e.3.

          In 7th operation we output whether the heap is empty
          or
          not i.e.false(0)
                  .

              In 8th operation we remove the maximum element from heap
                  .So the ne heap becomes->[4, 1]
                  .

              In 9th operation we change the 0th index element to 16. So
              new heap becomes->[16, 1]
                  .After heapify->[16, 1]
                  .

              In
              10th operation we output the maximum element of the heap i.e.16.

              Input : operation =
          [
            "initializeHeap", "insert", "insert", "exctractMax", "getMax",
            "insert", "heapSize", "isEmpty", "exctractMax", "changeKey",
            "getMax"
          ]

      nums = [ [4], [1], [4], [ 0, 2 ] ]

             Output : [ null, null, null, null, 1, null, 2, 0, null, null, 2 ]

                      Explanation :

    In 1st operation we initialize the heap to empty heap.

    In 2nd,
      3rd operation we insert 4,
      1 to the heap respectively.The heap after 4th operation will be->[4, 1]
              .

          In 4th operation we remove the maximum element from heap
              .So the ne heap becomes->[1]
              .

          In 5th operation we output the maximum element of the heap i.e
              .1.

          In 6th operation we operation we insert
          4 to the heap.The heap after 6th operation will be->[4, 1]
              .

          In 7th operation we output the size of the current heap i.e.2.

          In 8th operation we output whether the heap is empty
          or not i.e.false(0)
                     .

                 In 9th operation we remove the maximum element from heap
                     .So the ne heap becomes->[1]
                     .

                 In 10th operation we change the 0th index element to 2. So
                 new heap becomes->[2]
                     .

                 In
                 11th operation we output the maximum element of the heap i.e.2.

                 Constraints : 1 <= n
                 <= 105 - 105 <= nums[i] <= 105
*/
#include <bits/stdc++.h>
#include <climits>
#include <stdexcept>
using namespace std;

class MaxHeap {
  int capacity, size;
  int *heap;

public:
  MaxHeap(int cap) : capacity(cap), size(0), heap(new int[cap]) {};
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
      if (heap[parent] >= heap[i])
        break;
      int temp = heap[parent];
      heap[parent] = heap[i];
      heap[i] = temp;
      i = parent;
    }
  }

  int getMax() const {
    if (size == 0)
      throw std::runtime_error("Heap underflow");
    return heap[0];
  }

  int getMin() const {
    if (size == 0)
      return -1;
    int i = size / 2;
    int min_val = INT_MAX;
    while (i < size) {
      min_val = min(min_val, heap[i]);
      i++;
    }
    return min_val;
  }

  int heapSize() const { return size; }

  bool isEmpty() const { return size == 0; }

  // question assumes that value would be less than its parent so no need to
  // heapify
  void changeKey(int index, int new_val) {
    if (index < 0 || index >= size)
      throw std::runtime_error("Invalid Index");
    heap[index] = new_val;
  }

  int extractMax() {
    if (size == 0)
      return -1;
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
      int largest = i;

      if (left < size && heap[left] > heap[largest])
        largest = left;

      if (right < size && heap[right] > heap[largest])
        largest = right;

      if (largest == i)
        break;

      swap(heap[i], heap[largest]);
      i = largest;
    }
  }
};
