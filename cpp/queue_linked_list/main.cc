#include <iostream>
#include "Queue.cc"
#include "Queue.h"

int main() {
  jw::Queue<int> myQ;
  std::cout << "Empty? " << myQ.isEmpty() << std::endl;
  
  myQ.enqueue(5);
  myQ.enqueue(6);
  myQ.enqueue(7);
  myQ.enqueue(8);
  myQ.printDebug();

  std::cout << "Empty? " << myQ.isEmpty() << std::endl;
  std::cout << "Front Value: " << myQ.dequeue() << " removed.\n";
  myQ.printDebug();

  std::cout << "Empty? " << myQ.isEmpty() << std::endl;
  std::cout << "Front Value: " << myQ.dequeue() << " removed.\n";
  myQ.printDebug();
  
  std::cout << "Empty? " << myQ.isEmpty() << std::endl;
  std::cout << "Front Value: " << myQ.dequeue() << " removed.\n";
  myQ.printDebug();

  std::cout << "Empty? " << myQ.isEmpty() << std::endl;
  std::cout << "Front Value: " << myQ.dequeue() << " removed.\n";
  myQ.printDebug();

  std::cout << "Empty? " << myQ.isEmpty() << std::endl;
  std::cout << "Front Value: " << myQ.dequeue() << " removed.\n";
  myQ.printDebug();

  return 0;
}