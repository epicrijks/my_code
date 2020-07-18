#include <iostream>

#include "MaxHeap.h"

int main() {
  int SIZE = 2;
  int data[] {6, 3};

  for (int i = 0; i < SIZE; ++i)
    std::cout << data[i] << " ";
  std::cout << std::endl;

  jw::heapify(data, SIZE);
  for (int i = 0; i < SIZE; ++i)
    std::cout << data[i] << " ";
  std::cout << std::endl;

  jw::heapSort(data, SIZE);
  for (int i = 0; i < SIZE; ++i)
    std::cout << data[i] << " ";
  std::cout << std::endl;

  return 0;
}