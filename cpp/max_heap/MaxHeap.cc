#include <iostream>
#include <string>

#include "MaxHeap.h"

namespace jw {

MaxHeap::MaxHeap(int size) {
  if (size > 0 && size < INT_MAX) {
    capacity = size;
    this->size = 0;
    data = new HeapElement[size];
  } else {
    std::cout << "ERROR: Invalid size.";
  }
}

MaxHeap::~MaxHeap() {
  delete[] data;
}

void MaxHeap::printDebug() {
  for (int i = 0; i < size; i++) {
    std::cout << data[i].key << " : " << data[i].value << "\n";
  }
}

void MaxHeap::insert(const int newKey, const std::string newValue) {
  if (size < capacity) {
    data[size].key = newKey;
    data[size].value = newValue;
    size++;
    siftUp(size-1);
  } else {
    std::cout << "Heap is full. Entry not added.\n";
  }
}

void MaxHeap::remove(int index) {
  if (index < size && index > 0) {
    swap(index, size-1);
    size--;
    siftDown(index);
  } else {
    std::cout << "ERROR: Invalid index.\n";
  }
}

HeapElement* MaxHeap::getMax() {
  if (size > 0) {
    return &(data[0]);
  } else {
    std::cout << "Heap is empty.\n";
    return NULL;
  }
}

HeapElement* MaxHeap::extractMax() {
  if (size > 0) {
    swap(0, size-1);
    size--;
    siftDown(0);
    return &(data[size]);
  } else {
    std::cout << "ERROR: Heap is empty.\n";
    return NULL;
  }
}

int MaxHeap::getSize() {
  return size;
}

bool MaxHeap::isEmpty() {
  return size == 0;
}

void MaxHeap::siftUp(int child) {
  int parent = (child - 1) / 2;
  bool swapped = true;

  while (child > 0 && swapped) {
    swapped = false;
    if (data[child].key > data[parent].key) {
      swap(child, parent);
      swapped = true;
      child = parent;
      parent = (child - 1) / 2;
    }   
  }
}

void MaxHeap::siftDown(int parent) {
  bool swapped = true;
  int leftChild = (parent * 2) + 1,
        rightChild = (parent * 2) + 2,
        childToSwap;
  
  while (parent < size && swapped && leftChild < size) {
    swapped = false;
    
    // If a right child exists, compare left and right child for max
    if (rightChild < size)
      childToSwap = (data[leftChild].key > data[rightChild].key) ? leftChild : rightChild;
    else // If only left child, no comparison needed
      childToSwap = leftChild;

    // If a swap is necessary
    if (data[parent].key < data[childToSwap].key) {
      swap(parent, childToSwap);
      swapped = true;
      parent = childToSwap;
      leftChild = (parent * 2) + 1;
      rightChild = (parent * 2) + 2;
    }
  }
}

void MaxHeap::swap(int a, int b) {
  HeapElement temp;
  temp.key = data[a].key;
  temp.value = data[a].value;
  data[a].key = data[b].key;
  data[a].value = data[b].value;
  data[b].key = temp.key;
  data[b].value = temp.value;
}

void heapify(int* values, int size) {
  for (int index = size / 2 - 1; index >=0; --index) {
    bubbleDown(values, size, index);
  }
}

void heapSort(int* values, int size) {
  heapify(values, size);

  for (int index = size - 1; index > 0; --index) {
    int temp = values[0];
    values[0] = values[index];
    values[index] = temp;
    bubbleDown(values, index, 0);
  }
}

void bubbleDown(int* values, int size, int index) {
  bool swapped = true;
  int leftChild = (index * 2) + 1,
        rightChild = (index * 2) + 2,
        childToSwap;
  
  while (index < size && swapped && leftChild < size) {
    swapped = false;
    
    // If a right child exists, compare left and right child for max
    if (rightChild < size)
      childToSwap = (values[leftChild] > values[rightChild]) ? leftChild : rightChild;
    else // If only left child, no comparison needed
      childToSwap = leftChild;

    // If a swap is necessary
    if (values[index] < values[childToSwap]) {
      int temp = values[index];
      values[index] = values[childToSwap];
      values[childToSwap] = temp;
      swapped = true;
      index = childToSwap;
      leftChild = (index * 2) + 1;
      rightChild = (index * 2) + 2;
    }
  }
}

}