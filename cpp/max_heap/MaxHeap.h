#include <string>

#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

namespace jw {

struct HeapElement {
  int key;
  std::string value;
};

class MaxHeap {
 public:
  MaxHeap(int size);
  ~MaxHeap();

  void printDebug();
  void insert(const int, const std::string);
  void remove(int);

  HeapElement* getMax();
  HeapElement* extractMax();
  int getSize();

  bool isEmpty();

 private:
  HeapElement* data;
  int capacity;
  int size;

  void siftUp(int);
  void siftDown(int);
  void swap(int, int);
};

// void heapify(int*);
// void heapSort(int*);

}

#endif