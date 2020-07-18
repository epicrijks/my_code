#include <iostream>

#include "MaxHeap.h"

int main() {
  jw::MaxHeap mheap(15);

  mheap.insert(43, "Marker");
  mheap.insert(42, "Pen");
  mheap.insert(36, "Jerod");
  mheap.insert(11, "Mom");
  mheap.insert(2, "Bottle");
  mheap.insert(13, "Chair");
  mheap.insert(1, "Vegetable");
  mheap.insert(8, "Firefly");
  mheap.insert(9, "Squash");

  mheap.printDebug();
  std::cout << std::endl;

  return 0;
}