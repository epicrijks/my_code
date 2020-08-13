#include <iostream>
#include "Queue.cc"
#include "Queue.h"

int main() {
  jw::Queue<int> myQ(3);
  myQ.enqueue(1);
  myQ.enqueue(-31);
  myQ.enqueue(20);
  myQ.enqueue(50);
  myQ.printDebug();

  int one = 0, two = 0, three = 0;
  myQ.dequeue(one);
  myQ.dequeue(two);
  myQ.dequeue(three);

  std::cout << "Popping: " << one << std::endl;
  std::cout << "Popping: " << two << std::endl;
  std::cout << "Popping: " << three << std::endl;

  return 0;
}